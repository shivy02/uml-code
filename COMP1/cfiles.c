#include<stdio.h>
#include<stdlib.h>

typedef struct student{

	char name[10];
	int grade;

} STUDENT;


int main (void){

FILE* myfile; //myfile is a pointer to a FILE object. 
//values that myfile can store? : address or NULL, 0

//opening file
myfile = fopen("class.txt", "r");

if (myfile == NULL){
	printf("Sorry no file \n");
	exit(1);
}
char c;
//fgetc and fgets returns end of file when it comes to the end
/*
while ( (c = fgetc(myfile)) != EOF){
 printf("char:'%c'\n",c);
}
*/
STUDENT mystudent;


while ( !feof(myfile)){
 fscanf(myfile, "%s %d",mystudent.name, &mystudent.grade);
 printf("%s %d\n",mystudent.name, mystudent.grade);
 }
 
 //read these into a structure

char* myname;
printf("Enter name ");
fscanf(stdin,"%s", myname);
printf("%s", myname);

fclose(myfile);

return 0;

}

