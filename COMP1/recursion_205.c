#include<stdio.h>

void clearKB(void);
void clearKB_Recursive(void);

int main (void){
char a, b, c;

printf("Enter character 1 ");
scanf("%c", &a);
clearKB_Recursive();


printf("Enter character 2 ");
scanf("%c", &b);
clearKB_Recursive();

printf("Enter character 3 ");
scanf("%c", &c);
clearKB_Recursive();

printf("Characters are: %c %c %c \n", a, b, c);

return 0;
}
void clearKB(void){
	char ch;
	scanf("%c", &ch);
	printf("Character in Buffer : %c \n", ch);
	while (ch != '\n'){
		scanf("%c", &ch);
		printf("Character in Buffer : %c \n", ch);
	
	}
	return;

}

void clearKB_Recursive(void) {

char ch;
	scanf("%c", &ch);
	printf("Character in Buffer : %c \n", ch);
	if (ch != '\n'){
		clearKB_Recursive();
	}
	return;

}