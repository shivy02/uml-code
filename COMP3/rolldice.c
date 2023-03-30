#include <stdio.h>
#include <stdlib.h>

int findSum(int arr[], int length);
double findAverage(int arr[], int length);

int main(void) {

    int numDice;
    int *diceVal;
    printf("Please enter the number from 2-5 for the number of dice: ");
    scanf("%d", &numDice);

    while(numDice < 2 || numDice > 5) {
        printf("Please enter a valid number from 2-5: ");
        scanf("%d", &numDice);
    };

    diceVal = (int*)malloc(numDice * sizeof(int));
    int counter = 1;

    for(int i = 0; i <= numDice-1; i++){
        diceVal[i] = (rand() % 6) + 1;
        printf("Dice %d: %d\n", counter, diceVal[i]);
        counter++;
    }
    
    int sum = findSum(diceVal, numDice);
    double average = findAverage(diceVal, numDice);
    
    printf("The sum of all the numbers is: %d\n", sum);
    printf("The average of all the numbers is: %0.2f", average);
    
    return 0;
};

int findSum(int arr[], int length) {
    int sum = 0;
    for(int i = 0; i <= length-1; i++){
        sum = sum + arr[i];
    };
    return sum;
};

double findAverage(int arr[], int length) {
    double sum = 0;
    for(int i = 0; i <= length-1; i++){
        sum = sum + arr[i];
    };
    return  sum/length;
};
