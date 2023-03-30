#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <string>
#include <fstream>

using namespace std;


int main(int argc, char* argv[]) {


    map<string, map<string, int> > ratings;
    ifstream inFile;
    string inputString, ratingString, movie;

    inFile.open("input.txt"); //open file

    string input;
    //check if file open
    if (inFile.fail()) {
        cerr << "ERROR: Could not open file" << endl;
        exit(1);

    }

    getline(inFile, ratingString);
    int numRatings = stoi(ratingString.c_str());    //convert ratingString to a number and store in numReviews
       
    for (int i = 0; i < numRatings; ++i) {
        getline(inFile, movie);
        getline(inFile, ratingString);
        int rating = stoi(ratingString.c_str());
        if (ratings.find(movie) != ratings.end()) {
            ratings[movie]["numReviews"]++;
            ratings[movie]["totalRatings"] += rating;
        }
        else {
            ratings[movie]["numReviews"] = 1;
            ratings[movie]["totalRatings"] = rating;
        }
    }
    int sum, a;

        map<string,int>::iterator p;
    for (auto p = ratings.begin(); p != ratings.end(); ++p) {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint); 
        cout.precision(2);  //output to a precision of 2

        if(p->second["numReviews"] > 1){
            cout << p->first << ": " << p->second["numReviews"] << " reviews, Average of " << p->second["totalRatings"] / (double)p->second["numReviews"] << " / 5" << endl;
        }else{
            cout << p->first << ": " << p->second["numReviews"] << " review, Average of " << p->second["totalRatings"] / (double)p->second["numReviews"] << " / 5" << endl;
        }

    }

    return 0;
}