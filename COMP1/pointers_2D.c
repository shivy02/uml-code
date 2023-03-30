#include<stdio.h>
#include<stdlib.h> //dynamic memory allocation

struct student{
	int std_ID;
	float std_GPA;
};

typedef struct student STUDENT;

int main (void){
	int* nums;
	int n; 
	printf("Enter size: ");
	scanf("%d", &n);
	nums = (int*) malloc (n * sizeof(int));
	//catch error from malloc
	if (nums == NULL){
		printf("no memory \n");
		exit(1);
	}
	for (int i = 0; i<n; i++){
		*(nums + i) = rand()%100;
		printf("%d %d \t %p %p \n", *(nums+i), nums[i], &nums[i], nums + i);
	}

	free(nums);
	
	return 0;

}
