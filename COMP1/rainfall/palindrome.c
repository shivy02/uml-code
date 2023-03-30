#include <stdio.h>

int isPalindrome(char str[]);

int main(void) {

    char str[] = "racecar";
    char str2[] = "hello";

    printf("%d\n", isPalindrome(str));
    printf("%d\n", isPalindrome(str2));

    return 0;
}

int isPalindrome(char str[]){

    int length;
    int i;
    int first = 0;

    for (i = 0; str[i] != '\0'; ++i);
    printf("Length of the string: %d\n", i);

    i = i-1;

    while(i > 1) {
        if(str[first++] != str[length--]){
            return 0;
        }

    }

    return 1;

    }
