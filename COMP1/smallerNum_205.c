#include <stdio.h>


int giveSmallerNumber(int a, int b) {

if (a < b) {
	return a;
}
else{
	return b;
}

}

int main(void){
	int a;
	int b;
	

	printf("Please input an integer: \n");
	scanf("%d", &a);

	printf("Please input another integer: \n");
	scanf("%d", &b);
	
	

	printf("Smaller number is: %d \n",  giveSmallerNumber(a, b));

	
	return 0;
}


//Your function definition goes here
