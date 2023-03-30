#include <stdio.h>
#include <ctype.h>

int hasBothCases(char str[]);

int main(void) {

    char str[10] = "Eusdfe";
    int number = hasBothCases(str);

    printf("%d", number);
    return 0;
}

int hasBothCases(char str[]) {
int i;
int length;
char letterOne;
char letterTwo;

while(str[i] != '\0') {
    i++;
}
length = i;

for(i = 0; i < length; i++) {

    if (str[i] >= 'A' && str[i] <= 'Z'){
        letterOne = str[i];
    }
}

for(i = 0; i < length; i++) {
    if (letterOne == str[i] + 32) {
        return 1;
    }
}
return 0;

}