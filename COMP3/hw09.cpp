/***********************************************
Author: Shivam Patel
Date: 11/15/21
Purpose: The purpose of this program is to use override functions
         in order to play a game that we made earlier this year and
         have the player eplay against a computer
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
Date: 11/15/21
Name: Shivam Patel
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//Player Class
class Player {
public:
    Player(string name) : name(name), wins(0) {}
    virtual int getGuess(int max, int min) { return 0; }
    virtual int checkMin(int guess, int answer, int min) = 0;
    virtual int checkMax(int guess, int answer, int max) = 0;
    int getWins() { return wins; }
    string getName() { return name; }
    void setName(string newName) { name = newName; }
    void setWins(int newWin) { wins = newWin; }
private:
    string name;
    int wins;
};

class HumanPlayer : public Player {
public:
    int getGuess(int max, int min)override{
        int input;
        cout << "Please enter your guess [0 - 100]: ";
        cin >> input;
        return input;
    }
    HumanPlayer(string name) : Player(name) {}
    virtual int checkMin(int guess, int answer, int min)override{
        if (guess < answer)
            min = guess + 1;
        return min;
    }
    virtual int checkMax(int guess, int answer, int max)override {
        if (guess > answer)
            max = guess - 1;
        return max;
    }
};

class ComputerPlayer : public Player {
public:
    ComputerPlayer(string name) : Player(name) {}
    int getGuess(int min, int max) { return rand() % 100; }
    virtual int checkMin(int guess, int answer, int min)override {
        if (guess < answer)
            min = guess + 1;
        return min;
    }
    virtual int checkMax(int guess, int answer, int max)override {
        if (guess > answer)
            max = guess - 1;
        return max;
    }
};

bool checkWin(int guess, int answer) {
    cout << "You guessed " << guess << ". \n";
    if (answer == guess) {
        cout << "You're right! You win!" << endl; // guessed right
        return true;
    }
    else if (answer < guess) {
        cout << "Your guess was too high.\n" << endl;
    }
    else {
        cout << "Your guess was too low.\n" << endl;
    }
    return false; //check if the guess is too high or low and return true if its right, else return false
}

void play(Player& player1, Player& player2) {
    int ans = 0, guess = 0;
    srand((int)time(0));
    ans = rand() % 100;
    bool win = false;
    int max = 100;
    int min = 0;
    while (!win) {
        cout << player1.getName() << "'s turn to guess:" << endl;
        guess = player1.getGuess(max, min);
        win = checkWin(guess, ans);
        max = player1.checkMax(guess, ans, max);
        min = player1.checkMin(guess, ans, min);
        if (win) {
            player1.setWins(player1.getWins() + 1);
            return;
        }
        cout << player2.getName() << "'s turn to guess:" << endl;
        guess = player2.getGuess(max, min);
        max = player2.checkMax(guess, ans, max);
        min = player2.checkMin(guess, ans, min);
        win = checkWin(guess, ans);
        if (win) {
            player2.setWins(player2.getWins() + 1);
        }
    }
}

int main() {
    HumanPlayer human1("Player 1"), human2("Player 2");
    ComputerPlayer computer1("Computer Player 1"), computer2("Computer Player 2");

    cout << "Select the game type (1-3) from the menu:" << endl
        << "1. Human vs. Human" << endl
        << "2. Human vs. Computer" << endl
        << "3. Computer vs. Computer" << endl
        << "Enter any other key to end the game." << endl;
    cout << "#";
    int input = 0;
    cin >> input;
    while (input < 4 && input > 0) 
    {
        if (input == 1)
        {
            play(human1, human2);
        }
        else if (input == 2)
        {
            play(human1, computer2);
        }
        else
        {
            play(computer1, computer2);
        }
        cout << "\nSelect the game type (1-3) from the menu, any other number to quit" << endl
            << "1. Human vs. Human" << endl
            << "2. Human vs. Computer" << endl
            << "3. Computer vs. Computer" << endl;
        cout << "#";
        cin >> input;

    }

    cout << "\n** GAME OVER **" << endl;

}