/***********************************************
Author: Shivam Patel
Date: 11/23/21
Purpose: This program modifies a dynamic array
Sources of Help: Stack Overflow
Time Spent: 1hr
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
Date: 11/23/21
Name: Shivam Patel
*/

#include <iostream>
#include <string>
#include <new>
#include <string>

using namespace std;

void testPFArrayD(void);
void testException(void);

class OutOfRange{
    public:

    OutOfRange(string aMessage, int anIndex): numIndex(anIndex), msg(aMessage){}

    string err(){
        return msg;
    }

    int index(){
        return numIndex;
    }

    private:
    int numIndex;
    string msg;

};
//Objects of this class are partially filled arrays of doubles.
class PFArrayD
{
public:
    PFArrayD( ): capacity(50), used(0), a(new double[50]){}
    //Initializes with a capacity of 50.
    
    PFArrayD(int capacityValue){
        capacity = capacityValue;
        used = 0;
        a = new double[capacity];
    }
    
    PFArrayD(const PFArrayD& pfaObject);
    
    void addElement(double element){
        bool isFull = full();
        if(isFull){
                throw OutOfRange("The array is already full. ", used+1);
            }
            a[this->used] = element;
            this->used +=1;
    }
    //Precondition: The array is not full.
    //Postcondition: The element has been added.
    
    bool full( ) const { return (capacity == used); }
    //Returns true if the array is full, false otherwise.
    
    int getCapacity( ) const { return capacity; }
    
    int getNumberUsed( ) const { return used; }
    
    void emptyArray( ){

        for(int i = 0; i <= capacity; i++){
            a[i] = 0.0;
        }

        used = 0;
        capacity = 0;
    }
    //Empties the array.
    
    double& operator[](int index) const{

        bool isFull = full();

        if((index >= used) && (index < 0)){
                throw OutOfRange("Can't access this index.", index);
            }
        return a[index];
    }
    //Read and change access to elements 0 through numberUsed - 1.
    
    PFArrayD& operator =(const PFArrayD& rightSide) {
        PFArrayD temp(rightSide);

        if (this->capacity != 0)
            delete[] this->a;

        this->capacity = rightSide.getCapacity();
        this->a = new double[this->capacity];  // the array is properly copied to the target object 
        
        for (int i = 0; i < this->capacity; i++)
            this->a[i] = rightSide[i];

        return *this;
    }
    
    ~PFArrayD( ){
        capacity = 0;
        used = 0;
        delete []a;
    }
private:
    double *a; //for an array of doubles.
    int capacity; //for the size of the array.
    int used; //for the number of array positions currently in use.
    
};

int main(int argc, char *argv[])
{
     cout << "This program tests the class OutOfRange.\n";
     testException();

     cout << endl;
     cout << "This program tests the class PFArrayD.\n";
     char ans;
     do
     {
         testPFArrayD( );
         cout << "Test again? (y/n) ";
         cin >> ans;
     }while ((ans == 'y') || (ans == 'Y'));
     
    return 0;
}

void testPFArrayD( )
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);
    
    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";
    
    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full( )))
    {
        temp.addElement(next);
        cin >> next;
    }
    
    cout << "You entered the following "
    << temp.getNumberUsed( ) << " numbers:\n";
    int index;
    int count = temp.getNumberUsed( );
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
    cout << "(plus a sentinel value.)\n";
}

void testException(){
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);

    try{
        
        cout << "Testing Exception: Adding " << temp.getCapacity() +  1 << " elements to the array." << endl << endl;
        int i;
        for(i = 0; i < cap+1; i++){
            temp.addElement(i);
            cout << temp[i] << endl;
        }
    }

    catch(OutOfRange &ex){
                cout << "ERROR:" << ex.err() << "\nAt index:" << ex.index() << endl;
            }
        
    }