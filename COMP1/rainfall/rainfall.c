#include <stdio.h>
#include <stdlib.h>

void average();

int main()
{
average();
return 0;
}

void average(){
    int counter=0;
    float rainFall;
    float railFallSum=0;

    //printf("Enter the Rainfall:");
    //scanf("%d",&rainFall);
    while (rainFall != 99999){
        printf("Enter the Rainfall:");
        scanf("%f",&rainFall);
        if (rainFall != 99999){
            railFallSum+=rainFall;
            counter++;
        }
    }

printf("Average RainFall: %f\n",railFallSum/counter);

}