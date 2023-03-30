#include <stdio.h>

int isPalindrome(str[]);

int main(void) {


    return 0;
}

int isPalindrome(str[]){

    int length;
    int i;
    int first = 0;

    while(str[i] != '\0') {
        i++;
    }

    length = i;

    if (str[first] != str[length]) {
        return 0;
    }

    if (first < (length + 1)) {
        while (str[first] != str[length + 1]) {
            first++;
            length--;
            if (str[first] != str[length]) {
                return 0;
            }
        }
        return 1;
    }





}