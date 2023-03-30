/***********************************************
Author: Shivam Patel
Date: 11/7/21
Purpose: The purpose of this program is to use ineritance
		to represent vehicles and their owners.
Sources of Help: Stack Overflow
Time Spent: 1.5hr
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
Date: 11/7/21
Name: Shivam Patel
*/

#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
	Person():name("none") {}
	Person(string aName) :name(aName) {}
	Person(const Person& theObject) :name(theObject.name) {}

	string getName() const {
		return name;
	}

    void setName(string newName){
        name = newName;
    }

	Person& operator=(const Person& rightOp) {
		this->name = rightOp.getName();
		return *this;
	}

	friend istream& operator >>(istream& inStream, Person& aPerson) {
		
        string entry;
        getline(cin, entry);
        aPerson.setName(entry);
		return inStream;
	}

	friend ostream& operator <<(ostream& outStream, const Person& pObject) {

		cout << pObject.name;
		return outStream;

	}

private:
	string name;
};

class Vehicle {

public:
	Vehicle():vehicle("Unknown Manufacturer"), cylinders(0), owner(Person("Unknown Owner")){}
	Vehicle(const string& newvehicle, int newcylinders, const Person& newOwner):vehicle(newvehicle), cylinders(newcylinders), owner(newOwner){}
	Vehicle(const Vehicle& op):vehicle(op.vehicle), cylinders(op.cylinders), owner(op.owner){}
	Vehicle& operator=(const Vehicle& op){
		vehicle = op.vehicle;
		cylinders = op.cylinders;
		owner = op.owner;
		return *this;
	}

	string getvehicle() {
		return vehicle;
	}

	int getcylinders() {
		return cylinders;
	}

	Person getOwner() {
		return owner;
	}
    
	void setvehicle(const string& newvehicle) {
		vehicle = newvehicle;
	}

	void setcylinders(int newcylinders) {
		cylinders = newcylinders;
	}

	void setOwner(const Person& newOwner) {
		owner = newOwner;
	}

	friend ostream& operator <<(ostream& outStream, const Vehicle& op) {
		outStream << op.vehicle;
		outStream << op.cylinders;
		outStream << op.owner;
		return outStream;
	}

private:

	string vehicle;
	int cylinders;
	Person owner;
};

class Truck: public Vehicle{

public:
	Truck():loadingCapacity(0), towingCapacity(0){}
	Truck(string newvehicle, int newcylinders, const Person& newOwner, double newLoadingCapacity, int newTowingCapacity):Vehicle(newvehicle, newcylinders, newOwner), loadingCapacity(newLoadingCapacity), towingCapacity(newTowingCapacity){}
	Truck(const Truck& op):Vehicle(op),loadingCapacity(op.loadingCapacity), towingCapacity(op.towingCapacity){}
    
	Truck& operator=(const Truck& op){
		Vehicle::operator=(op);
		loadingCapacity = op.loadingCapacity;
		towingCapacity = op.towingCapacity;
		return *this;
	}

	double getLoadCapacity() {
		return loadingCapacity;
	}

	int getTowingCapacity() {
		return towingCapacity;
	}

	void setLoadCapacity(double newLoadingCapacity) {
		loadingCapacity = newLoadingCapacity;
	}

	void setTowingCapacity(int newTowingCapacity) {
		towingCapacity = newTowingCapacity;
	}

	friend ostream& operator <<(ostream& outStream, const Truck& pObject) {
		outStream << pObject.loadingCapacity;
		outStream << pObject.towingCapacity;
		return outStream;
	}

private:
	double loadingCapacity;
	int towingCapacity;
};

int main(int argc, const char* argv[]) {

	Person person1, person2, person3;
	cout << "TESTING PERSON CLASS" << endl;
	cout <<"Testing default const: the person is "<< person1 << endl;
	Person newPerson("Shivam Patel");
	cout << "Testing const.(string): I am: " << newPerson << endl;
	Person personCopy(newPerson);
	cout << "Testing copy constructor: another me is: " << personCopy << endl;
	cout << "Testing >> overloading: Enter your name: "; 
	cin >> person2;
	cout << "You're: "<< person2 << endl;
	person3 = person2;
	cout << "Testing = overloading: Another you is: " << person3 << endl;

	cout << "//////TESTING VEHICLE CLASS//////" << endl;
	Vehicle vehicle, vehicle2;
	cout << "Testing default construtor: the Vehicle is: "<< endl << vehicle.getvehicle() << ", " << vehicle.getcylinders()<<" cylinders, " << "belongs to: " << vehicle.getOwner() << endl;
	Vehicle camry("Camry", 8, newPerson);  
	cout << "Testing constructor(args): for my car: " << endl << camry.getvehicle() << ", " << camry.getcylinders() << " cylinders, " << "belongs to: " << camry.getOwner() << endl;
	Vehicle camryCopy(camry);
	cout << "Testing copy constructor: my second same car: " << endl << camryCopy.getvehicle() << ", " << camryCopy.getcylinders() << " cylinders, " << "belongs to: " << camryCopy.getOwner() << endl;
	Person f("Dev Patel");
	Vehicle v("Toyota", 6, f);
	Vehicle l = v;
	cout << "Testing = overloading: " << endl <<"your cars is: "<< l.getvehicle() << ", " << l.getcylinders() << " cylinders, " << "belongs to: " << l.getOwner() << endl;
	Vehicle g(l);
	cout <<"your second car is: " << g.getvehicle() << ", " << g.getcylinders() << " cylinders, " << "belongs to: " << g.getOwner() << endl;

	cout << "//////TESTING TRUCK CLASS///////" << endl;
	Truck truck;
	cout << "Testing default constructor: the Truck is:" << endl << truck.getvehicle() << ", " << truck.getcylinders() << " cylinders, " << "belongs to: " << truck.getOwner() << ", loading capacity: " << truck.getLoadCapacity() << ", towing capacity: " << truck.getTowingCapacity() << endl;
	Person k("Alex");
	Truck ramTruck("Ram Truck", 8, k, 250, 2000);
	cout << "Testing constructor(args): for person3 Truck:" << endl<<ramTruck.getvehicle() << ", " << ramTruck.getcylinders() << " cylinders, " << "belongs to: " << ramTruck.getOwner() << ", loading capacity: " << ramTruck.getLoadCapacity() << ", towing capacity: " << ramTruck.getTowingCapacity() << endl;
	Truck truckCopy(ramTruck);
	cout << "Testing copy constructor: copiede Truck:" << endl << truckCopy.getvehicle() << ", " << truckCopy.getcylinders() << " cylinders, " << "belongs to: " << truckCopy.getOwner() << ", loading capacity: " << truckCopy.getLoadCapacity() << ", towing capacity: " << truckCopy.getTowingCapacity() << endl;
	Truck t = ramTruck;
	cout << "Testing = overloading:" << endl<<"his truck: " << t.getvehicle() << ", " << t.getcylinders() << " cylinders, " << "belongs to: " << f << ", loading capacity: " << truckCopy.getLoadCapacity() << ", towing capacity: " << truckCopy.getTowingCapacity() << endl;
	cout <<"his same truck: " << t.getvehicle() << ", " << t.getcylinders() << " cylinders, " << "belongs to: " << f << ", loading capacity: " << truckCopy.getLoadCapacity() << ", towing capacity: " << truckCopy.getTowingCapacity() << endl;

	return 0;
}
