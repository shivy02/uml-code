 /***********************************************
Author: Shivam Patel
Date: 10/6/21
Purpose: The purpose of this program is to use operator overloading
         in order to perform operations on fractions.
Sources of Help: Stack overflow
Time Spent: 1.5 hours
***********************************************/
/*
Computing III -- COMP.2010 Honor Statement

The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.

I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.

Date: 10/6/21
Name: Shivam Patel
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Rational {

public:

    Rational():numerator(0), denominator(1){}
    Rational(int initWhole): numerator(initWhole), denominator(1){}
    Rational(int initNumerator, int initDenom):numerator(initNumerator), denominator(initDenom){}
    
    int getNumerator(void) const {
        return numerator;
    }

    int getDenominator(void) const{
        return denominator;
    }

    void setNumerator(int newNum) {
        numerator = newNum;
    }

    void setDenominator(int newDenom){
        denominator = newDenom;
    }

    void display(void) const;
    double toDecimal(void) const;

    void simplify() {

        int gcd = normalize(); //returns the greatest common divisor

        if (denominator < 0){
            denominator = denominator * -1;
            numerator = numerator * -1;
        }

        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }

private:

    int normalize(); //finds the greatest common divisor of the numerator and the denominator

    int numerator;
    int denominator;

};

const Rational operator +(const Rational &f1, const Rational &f2);
const Rational operator -(const Rational &f1, const Rational &f2);
bool operator <(const Rational &f1, const Rational &f2);
bool operator >(const Rational &f1, const Rational &f2);
bool operator >=(const Rational &f1, const Rational &f2);
bool operator <=(const Rational &f1, const Rational &f2);
bool operator ==(const Rational &f1, const Rational &f2);
Rational operator *(const Rational& f1, const Rational& f2);
Rational operator /(const Rational& f1, const Rational& f2);
ostream& operator<<(ostream& out, const Rational& fraction);
istream& operator>> (istream& in, Rational& fraction);


int main(int argc, const char * argv[]) {

    Rational f1;
    cout << "Please enter a fraction in the following format (\"a/b\"): \n";
    cin >> f1;
    cout << "Your first fraction: " << f1 << "\n"; //enter first fraction and store it in f1

    Rational f2;
    cout << "Please enter a second fraction in the following format (\"a/b\"): \n";
    cin >> f2;
    cout << "Your second fraction: " << f2 << "\n\n"; //enter second fraction and store it in f2

    int selection;
    char selection2 = 'y';
    Rational f3;

    if(f1 < f2){ //compare the two fractions
        cout << f1 << " is less than " << f2 << "\n\n";
    }else if(f1 > f2){
        cout << f1 << " is greater than " << f2 << "\n\n";
    }else if(f1 == f2){
        cout << f1 << " is equal to " << f2 << "\n\n";
    }

    if (f1 <= f2){
        cout << f1 << " is less than or equal to " << f2 << "\n\n";
    }
    if (f1 >= f2){
        cout << f1 << " is greater than or equal to " << f2 << "\n\n";
    }
    

    while(selection2 == 'y'){ //make a selection for which operation you want to perform on the fraction.

        cout << "Please select a number to do an operation to your fractions - \n\n 1: multiply \n 2: divide \n 3: add \n 4: subtract \n\n #";
        cin >> selection;
        cout << "\n";

        switch(selection){
            case 1:
                f3 = f1 * f2;
                cout << f1 << " * " << f2 << " = " << f3 << "\n\n";
                break;
            case 2:
                f3 = f1 / f2;
                cout << f1 << " / " << f2 << " = " << f3 << "\n\n";
                break;
            case 3:
                f3 = f1 + f2;
                cout << f1 << " + " << f2 << " = " << f3 << "\n\n";
                break;
            case 4:
                f3 = f1 - f2;
                cout << f1 << " - " << f2 << " = " << f3 << "\n\n";
                break;
        }
        
        cout << "Enter y make a different selection or n to quit: \n";
        cout << "y/n: ";
        cin >> selection2;
        cout << "\n";

    }
    
    return 0;
}

double Rational::toDecimal(void) const{
    return (double)numerator / denominator;
}

void Rational::display(void) const{
    cout << numerator << "/" << denominator << endl;
}

const Rational operator +(const Rational &f1, const Rational &f2){

    int denom1 = f1.getDenominator();
    int denom2 = f2.getDenominator();
    int lcm = 0;

    if(denom1 < denom2){  //compute the least common multiple
        lcm = denom1;
    }else{
        lcm = denom2;
    }

    while(1) {
      if( lcm % denom1 == 0 && lcm % denom2 == 0 ) {
         break;
      }
      lcm++;
   }

    int count1 = lcm / denom1; 
    int count2 = lcm / denom2;

    int num1 = f1.getNumerator();
    int num2 = f2.getNumerator();

    num1 = num1 * count1;
    num2 = num2 * count2;

    int num3 = num1 + num2;

    Rational f3(num3, lcm);

    f3.setDenominator(lcm);
    f3.setNumerator(num3);
    f3.simplify();

    return f3;
}

const Rational operator -(const Rational &f1, const Rational &f2){

    int denom1 = f1.getDenominator();
    int denom2 = f2.getDenominator();
    int lcm = 0;

    if(denom1 < denom2){ //find the least common multiple
        lcm = denom1;
    }else{
        lcm = denom2;
    }

    while(1) {
      if( lcm % denom1 == 0 && lcm % denom2 == 0 ) {
         break;
      }
      lcm++;
   }

    int count1 = lcm / denom1;
    int count2 = lcm / denom2;

    int num1 = f1.getNumerator();
    int num2 = f2.getNumerator();

    num1 = num1 * count1;
    num2 = num2 * count2;

    int num3 = num1 - num2;

    Rational f3(num3, lcm);

    f3.setDenominator(lcm);
    f3.setNumerator(num3);
    f3.simplify(); //set the values

    return f3;
}

bool operator <(const Rational &f1, const Rational &f2){

    double num1 = f1.toDecimal();
    double num2 = f2.toDecimal(); //convert the fraction value to a decimal so you can compare easily

    return (num1 < num2);
}

bool operator >(const Rational &f1, const Rational &f2){

    double num1 = f1.toDecimal();
    double num2 = f2.toDecimal(); //convert to decimal for comparison

    return (num1 > num2);
}

bool operator <=(const Rational &f1, const Rational &f2){

    double num1 = f1.toDecimal();
    double num2 = f2.toDecimal(); //convert to decimal for comparison

    return (num1 <= num2);

}
bool operator >=(const Rational &f1, const Rational &f2){

    double num1 = f1.toDecimal();
    double num2 = f2.toDecimal(); //convert to decimal for comparison

    return (num1 >= num2);

}

bool operator ==(const Rational &f1, const Rational &f2){

    int a = f1.getNumerator();
    int b = f1.getDenominator();
    int c = f2.getNumerator();
    int d = f2.getDenominator();


    return (a * d == c * b);
}

Rational operator *(const Rational& f1, const Rational& f2){

    int num = f1.getNumerator() * f2.getNumerator();
    int denom = f1.getDenominator() * f2.getDenominator();

    Rational f3(num, denom);
    f3.simplify();

    return f3;
}

Rational operator /(const Rational& f1, const Rational& f2){

    int num1 = f1.getNumerator();
    int num2 = f2.getNumerator();
    int denom1 = f1.getDenominator();
    int denom2 = f2.getDenominator();

    int temp; 
    temp = denom2;
    denom2 = num2;
    num2 = temp; //flip the numerator and denominator so you can multiply by the reciprocal

    int num = num1 * num2;
    int denom = denom1 * denom2;

    Rational f3(num, denom);
    f3.simplify();//simplify the object that will be returned

    return f3;
}

ostream& operator <<(ostream& out, const Rational& fraction){

    cout << fraction.getNumerator() << "/" << fraction.getDenominator();
    return out;

}

istream& operator >>(istream& in, Rational& fraction){

    int num;
    int denom;

    cin >> num;
    cin.ignore(numeric_limits<streamsize>::max(), '/');
    cin >> denom;

    while(denom == 0){
        cout << "Please enter a valid fraction in the following format (\"a/b\") without a 0 in the denominator: \n";
        cin >> num;
        cin.ignore(numeric_limits<streamsize>::max(), '/');
        cin >> denom;
    }

    fraction.setNumerator(num);
    fraction.setDenominator(denom);

    return in;

}

int Rational::normalize() { //this function returns the greatest common divisor of the numerator and denominator

    int R;
    int a = numerator;
    int b = denominator;

    if(a < 0){
        a = a * -1;
    }else if(b < 0){
        b = b * -1;
    }

    while((a % b) > 0){
        R = a % b;
        a = b;
        b = R;
    }
    return b;
}
