#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {

    map<string, int> container;
    string input;

    cout << "Enter a sentence: \n";

    while (cin >> input) { //scan the input until EOF
        ++container[input];
    }

    //prints the word and the assoiciated number
    for (map<string, int>::iterator i = container.begin(); i != container.end(); ++i)
    {
            cout << i->first << "\t" << i->second << "\n";
    }

    return 0;
}