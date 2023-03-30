/***********************************************
Author: Shivam Patel
Date: 9/12/21
Purpose: The purpose of this program is to create a game that can be restarted.
        It picks a random integer depoending on the range you guve it and you must
        guess the random value before your guesses are gone.
Sources of Help: None
Time Spent: 45 min
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
Date: 9/14/21
Name: Shivam Patel
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 1000;
const int MIN = 0;

void game(int maxNum, int minNum, int numGuesses); //this function contains the main dynamics of the game and is used to simplify when you have to restart

int main(int argc, char *argv[]){

    srand(time(0));

    char playAgain;
    int minNum; //minimum number in the range
    int maxNum; //maximum number in the range
    int numGuesses;

    cout << "\n\n******** Welcome to the Guessing Integer Game! ********\n";
    cout << "First, let's set up the game.\n";

    cout << "   Please enter the minimum number, a positive integer less than 1000: ";
    cin >> minNum;
    while(minNum <= MIN || minNum >= MAX){
        cout << "   Please enter a valid positive integer between 0 and 1000: "; //ask for the minimum number
        cin >> minNum;
    }

    cout << "   Please enter the maximum number, which is greater than the minimum (" << minNum << ") and less than 1000: ";
    cin >> maxNum;
    while(maxNum <= minNum || maxNum > MAX){
    cout << "   Please enter a valid positive integer between " <<  minNum << " and 1000: ";  //ask for the maximum number
    cin >> maxNum;
    }

    cout << "   Please enter the number of guesses allowed (less than 10): ";
    cin >> numGuesses;
    while(numGuesses <= MIN || numGuesses >= 10) {
        cout << "   Please enter the number of guesses allowed (less than 10): " ; //ask how many guesses they want
        cin >> numGuesses;
    }

    game(maxNum, minNum, numGuesses); //this is the main part of the game that gets played

    cout << "Would you like to play again (y or n)?\n";
    cin >> playAgain;

    if(playAgain == 'n' || playAgain == 'N') { //if the user selects n, the statement breaks and the program is terminated
       return 0; 
    }

        do{  
            game(maxNum, minNum, numGuesses); //Ask the user if they want to play again and keeps playing until the user enters n

            cout << "Would you like to play again (y or n)?\n";
            cin >> playAgain;

            if(playAgain == 'n' || playAgain == 'N') {
                break;
            }
        }while(playAgain == 'y' || playAgain == 'Y');

    return 0;
}

void game(int maxNum, int minNum, int numGuesses) {

    int key; //this is the number that the person has to guess
    int guess; //value that the player enters

    key = (rand() % maxNum) + minNum;

    //initial guess
    cout << "Now, I have number between " << minNum << " and " << maxNum << ". Can you guess my number? Please type your first guess:\n";
    cin >> guess;
    numGuesses = numGuesses - 1;
    if(guess < key){
        cout << "Too low! Number of guesses left: " << numGuesses << endl;
    }else if(guess > key){
        cout << "Too high! Number of guesses left: " << numGuesses <<  endl;
    }
    
    if(numGuesses != 0) {
        cout << "Try again.\n";
    }

    do{ 
        cin >> guess;
        numGuesses--;
            if(guess > key) {
                cout << "Too high! Number of guesses left: " << numGuesses <<  endl; //hint that the number they guessed is too high
                if(numGuesses != 0){
                    cout << "Try Again.\n";
                }
            } else if(guess < key){
                cout << "Too low! Number of guesses left: " << numGuesses << endl; //hint that the number they guessed is too low
                if(numGuesses != 0){
                    cout << "Try Again.\n";
                }
            }
            if(numGuesses == 0) { //break if there are no more guesses left
                break;
            }
            if(guess == key){
                break;
            }

    } while (guess != key || numGuesses != 0); //keep asking user to try again until the key is guessed or the number of guesses are done

    if (numGuesses == 0) {
        cout << "Sorry you ran out of tries. The number was: " << key << endl;
    } else if(guess == key) {
        cout << "Excellent! You guessed the number!\n"; // If the user guessed right
    }

    return;
}
