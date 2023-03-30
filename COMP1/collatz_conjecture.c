#include <stdio.h>

void clearKeyboardBuffer(void);
int stepCounter(int start); //function for the number of steps taken to reach 1 for any number.
 
int main(int argc, char * argv[]) {
    
    int start;
    int end;
    
    printf("Enter a starting point:\n");
    scanf("%d", &start);
    
    while(start<2 || start>99){ //while loop to keep us whithin 2 and 99.
        printf("Enter a valid starting point (from 2-99):\n");
        scanf("%d", &start);
    }
    clearKeyboardBuffer();
    
    printf("Enter an ending point:\n");
    scanf("%d", &end);
    
    while(end<start || end>999){ //while loop to keep us between our starting point and 999.
        printf("Enter a valid ending point (from %d-999):\n", start);
        scanf("%d", &end);
        clearKeyboardBuffer();
    }
    
    int i;
    int n = 0;
    
       for(i=start; i<=end; i++){
       
            printf("  %3d:%-3d  ",i, stepCounter(i)); //the %3d and %-3d are for allignment
            n++;
       
       if(n==7){ //This if statement will print a new line after 7 columns.
        printf("\n");
       n = 0;
       }
       
       }
    
    
    if(end !=99){
    printf("\n");
    }
    return 0;
}
 
int stepCounter(int start){ //function for the stepCounter
    int count = 0;
    
    while(start>1) {
       
       if(start%2 == 0)
       start = start/2;
       
       else 
       start = 3*start+1;
       
       
       
       count++;
       
    }
    
    return count;
}

void clearKeyboardBuffer(void) {
   char ch;
   scanf("%c", &ch);
   while (ch != '\n' && ch != '\0') {
      scanf("%c", &ch);
   }
}
       

