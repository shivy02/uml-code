/***********************************************
Author: Shivam Patel
Date: 10/18/21
Purpose: This program manipulates a dynamic array of strings.
Sources of Help: Stack Overflow
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
Date: 10/21/21
Name: Shivam Patel
*/

#include <iostream>
#include <string>
using namespace std;

class DynamicStringArray{

    public:

        DynamicStringArray(void);
		DynamicStringArray(const DynamicStringArray& op);
		int getSize(void) const {return size;};
		string getEntry(const int index) const;
		void operator = (const DynamicStringArray& op);
        void addEntry(string entry);
		bool deleteEntry(string entry);
        ~DynamicStringArray(void);

    private:

        string * dynamicArray;
        int size;

};

int main(void){

    DynamicStringArray bookShelf;
	bookShelf.addEntry("The first string\n");

	int strNum = bookShelf.getSize();
	for(int i = 0; i < strNum; i++)
		cout << bookShelf.getEntry(i);

	bookShelf.addEntry("seconds class string\n");

	//create a new dynamic string array before deleting anything
	DynamicStringArray newShelf(bookShelf);

	bookShelf.deleteEntry("The first string\n");
	bookShelf.deleteEntry("this isnt an entry");

	strNum = bookShelf.getSize();
	for(int i = 0; i < strNum; i++)
		cout << bookShelf.getEntry(i);

	cout << endl;

	strNum = newShelf.getSize();
	for(int i = 0; i < strNum; i++)
		cout << newShelf.getEntry(i);

	cout << endl;

	newShelf = bookShelf;
	strNum = newShelf.getSize();
	for(int i = 0; i < strNum; i++)
		cout << newShelf.getEntry(i);

    return 0;
} 

DynamicStringArray::DynamicStringArray(void){
	size = 0;
	dynamicArray = NULL;
}

DynamicStringArray::DynamicStringArray(const DynamicStringArray& op) {

	size = op.getSize();
	dynamicArray = new string[size];

	for(int i = 0; i < size; i++){
		dynamicArray[i] = op.getEntry(i);
	}
}

void DynamicStringArray::operator = (const DynamicStringArray& op){

	DynamicStringArray temp(op);
	if(this->size !=0){
		delete[] this->dynamicArray; //reset the size to 0 if it's not
    }

	this->size = op.getSize(); //set the size of the calling object
	this->dynamicArray = new string[this->size];
	for(int i = 0; i < this->size; i++)
		this->dynamicArray[i] = op.getEntry(i); //copy the contents of the right array into the left
}

void DynamicStringArray::addEntry(string entry){
	//keep track of the old array
	string * temp = dynamicArray;

	//create new array
	dynamicArray = new string[size + 1];
	dynamicArray[size].assign(entry);

	//copy old values
	for( int i = 0; i < size; i++){
		dynamicArray[i] = temp[i];
	}

	//dont try to delete the nullprt if this is the first std::string
	if(size > 0){
		delete[] temp; 
	}

	size++; //the size is one greater than the old array
}

bool DynamicStringArray::deleteEntry(string entry){

	bool found = false;

	int i;
	for(i = 0; i < size; i++){
		if(entry == dynamicArray[i]){
			found = true;
			break;
		} //find the entry to be deleted
	}

	if(found == true){

		string * temp = dynamicArray;

		for(int j; j < size; j++){
			if(j < i){
				dynamicArray[j] = temp[j];
			}else if(j > i){
				dynamicArray[j - 1] = temp[j];
			}
		} //copy all entries except the deleted entry
		size--; //size is one less
	}

	return found;
}


string DynamicStringArray::getEntry(const int index) const{

	if(index >= size){
		return NULL; //check if the index we are trying to access exists
	}else{
		return dynamicArray[index]; //return a pointer that references to the string at that indexx
	}
}

DynamicStringArray::~DynamicStringArray(void){ //destructor

	delete[] dynamicArray; //free the memory
}