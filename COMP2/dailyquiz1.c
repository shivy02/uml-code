#include <stdio.h>

char* reverse(char *string);

int main(void) {
    char word[] = "Happy Birthday!";
    printf("%s\n", word);
    reverse(word);
    printf("%s\n", word);
    printf("%s\n", reverse(word));
    printf("%s\n", word);

    return 0;
}

char* reverse(char *string) {

    int size = 0;
    char temp;
    int i;

    while(string[size] != '\0') {
        size++;
    }

    for(i = 0; i < size/2; i++) {
        temp = string[i];
        string[i] = string[size - (i + 1)];
        string[size - (i + 1)] = temp;
    }


    return string;
}