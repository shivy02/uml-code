/***********************************************
Author: Shivam Patel
Date: 9/24/21
Purpose: The purpose of this program is to convert a zipcode to a barcode
         and vice versa via postnet protocol using a class.
Sources of Help: Stack Overflow
Time Spent: 2 hours
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
Date: 9/24/21
Name: Shivam Patel
*/

#include <iostream>
#include <string>
using namespace std;

enum string_code { //this is so that I can use an enum when converting from barcode to zipcode since it is a string
    e11000,
    e00011,
    e00101,
    e00110,
    e01001,
    e01010,
    e01100,
    e10001,
    e10010,
    e10100
};

string_code hashit (std::string const& inString); //returns an integer value from a string value to put in to my switch statement.

class ZipCode {
    
    public:
        //constructors
        ZipCode(int iZipCode);
        ZipCode(string iBarCode);

        //accessors
        string getBarCode()const;
        int getZipCode()const;



    private:

        int zipCode;
        string barCode;

        void findBarCode(int zipCode);
        void findZipCode(string barCode);

};


int main(int argc, char * argv[]) {
    ZipCode zip(99504),
    zip2("100101010011100001100110001"),
    zip3(12345),
    zip4(67890);
    
    cout << zip.getZipCode() << "'s bar code is '"
    << zip.getBarCode() << "'" << endl;
    cout << zip2.getZipCode() << "'s bar code is '"
    << zip2.getBarCode() << "'" << endl;
    cout << zip3.getZipCode() << "'s bar code is '"
    << zip3.getBarCode() << "'" << endl;
    cout << zip4.getZipCode() << "'s bar code is '"
    << zip4.getBarCode() << "'" << endl;
    
    cout << endl;
    
    // Test a range of values by first constructing a zip code
    // with an integer, then retrieving the bar code and using
    // that to construct another ZipCode.
    int zip_int = 0;
    for (int i = 0; i < 25; i++)
    {
        // Make an aribrary 5-digit zip code integer, and use it
        // to construct a ZipCode
        int five_digit_zip = (zip_int * zip_int) % 100000;
        ZipCode z1(five_digit_zip);
        
        // Construct a second ZipCode from the first's bar code
        string z1_barcode = z1.getBarCode();
        ZipCode z2(z1_barcode);
        
        cout.width(3);
        cout << (i + 1) << ": ";
        cout.width(5);
        cout << z2.getZipCode() << " has code '"
        << z1_barcode << "'";
        
        if ((z1_barcode == z2.getBarCode()) &&
            (z1.getZipCode() == z2.getZipCode()) &&
            (z2.getZipCode() == five_digit_zip))
        {
            cout << " [OK]" << endl;
        }
        else
        {
            cout << " [ERR]" << endl;
        }
        
        // Increment the test value arbitrarily
        zip_int += (233 + zip_int % 7);
    }
    cout << endl;
    
    // Test some error conditions. This test assumes that
    // ZipCode will simply set its value to a flag that indicates
    // an error, and will not exit the program.
    int BAD_ZIP_COUNT = 2;
    string bad_zips[][2] = {
        { "100101010011100001100110000", "bad start/end character" },
        { "100101010011100001100110021", "bad digit" },
    };
    for (int i = 0; i < BAD_ZIP_COUNT; i++)
    {
        cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;
        ZipCode test(bad_zips[i][0]);
        cout << endl;
    }
    
    cout << "Enter a character to quit." << endl;
    char c;
    cin >> c;
    return 0;
}

string_code hashit(std::string const& inString) { //this function returns enum values for the chunks of five digits so that a switch case statement may be used
    if (inString == "11000") return e11000;
    if (inString == "00011") return e00011;
    if (inString == "00101") return e00101;
    if (inString == "00110") return e00110;
    if (inString == "01001") return e01001;
    if (inString == "01010") return e01010;
    if (inString == "01100") return e01100;
    if (inString == "10001") return e10001;
    if (inString == "10010") return e10010;
    if (inString == "10100") return e10100;
}

ZipCode::ZipCode(int iZipCode){
    zipCode = iZipCode;
    barCode = ""; //initialize empty barcode
    
    findBarCode(zipCode); //call function that finds and sets the barcode value depending on the zipcode
}

ZipCode::ZipCode(string iBarCode){
    barCode = iBarCode;
    zipCode = 0; //initalize zipcode to 0
    
    findZipCode(barCode); //find the zipcode depending on the bar code
}

string ZipCode::getBarCode()const{
    return barCode;
}

int ZipCode::getZipCode()const{
    return zipCode;
}

void ZipCode::findZipCode(string barCode){

    if (barCode[26] != '1'){
        cout << "Bad end character in the barcode!\n";
    } else if(barCode[0] != '1'){
        cout << "Bad start character in the barcode! \n";
    }

    int i = 0;

    while(i < 26){
        if(barCode[i] != '1' && barCode[i] != '0'){
            cout << "Bad Digit in the barcode!\n";
        }
        i++;
    }

    barCode = barCode.substr(1);
    barCode = barCode.substr(0, 25); //drop off the first and last digits

    string fiveDigits;
	fiveDigits = barCode.substr(0, 5);

    if(barCode == "111000110001100011000110001"){
        zipCode = 0;
    }
	

	do {
		fiveDigits = barCode.substr(0, 5);
		barCode = barCode.substr(5);

        switch(hashit(fiveDigits)){
            case e11000:
                zipCode = zipCode * 10 + 0;
                break;
            case e00011:
                zipCode = zipCode * 10 + 1;
                break;
            case e00101:
                zipCode = zipCode * 10 + 2;
                break;
            case e00110:
                zipCode = zipCode * 10 + 3;
                break;
            case e01001:
                zipCode = zipCode * 10 + 4;
                break;
            case e01010:
                zipCode = zipCode * 10 + 5;
                break;
            case e01100:
                zipCode = zipCode * 10 + 6;
                break;
            case e10001:
                zipCode = zipCode * 10 + 7;
                break;
            case e10010:
                zipCode = zipCode * 10 + 8;
                break;
            case e10100:
                zipCode = zipCode * 10 + 9;
                break;
            default: 
                cout << "Error in the barcode string." << endl;
			    exit(1);
        }
	}while (barCode.length() > 0);
}

void ZipCode::findBarCode(int zipCode) {

    int zip_digit;
    int zipCount = 0;

    if (zipCode == 0){
        barCode = "111000110001100011000110001";
        return;
    }

    do {
        zip_digit = zipCode % 10; //sets the digit to put in the switch statement
        zipCode = zipCode / 10; //keep dividing by 10 until there are no digits left
        zipCount++;

        if(zipCount < 4 && zipCode <= 0) {
            zip_digit = 0;
        }

        switch (zip_digit) { 
        case 0: 
            barCode = "11000" + barCode;
            break;
        case 1: 
            barCode = "00011" + barCode;
            break;
        case 2: 
            barCode = "00101" + barCode;
            break;
        case 3: 
            barCode = "00110" + barCode;
            break;
        case 4: 
            barCode = "01001" + barCode;
            break;
        case 5: 
            barCode = "01010" + barCode;
            break;
        case 6: 
            barCode = "01100" + barCode;
            break;
        case 7: 
            barCode = "10001" + barCode;
            break;
        case 8: 
            barCode = "10010" + barCode;
            break;
        case 9: 
            barCode = "10100" + barCode;
            break;
        default:
            barCode = "Error in the barcode";
            break;
        }
    }while (zipCode > 0 || zipCount != 5);

    barCode = barCode + "1";
    barCode = barCode.insert(0, "1"); //add back the first and last digits
}

