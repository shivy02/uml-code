#include <stdio.h>
#include <stdlib.h>

int main()
{
int n=0,i=1, arr[100], new_arr[100],flag;
printf("Enter numbers (to stop enter -1): \n");
  
//read integers untill -1
do
{
scanf("%d",&arr[n]);
n++;

}while(arr[n-1]!=-1);

//remove duplicates and negative numbers
new_arr[0]=arr[0];
for(int j=1;j<n;j++){
flag=0;
if(arr[j]>0){
for(int k=0;k<i;k++){
if(new_arr[k]==arr[j])
flag=1;

}
if(flag==0){
new_arr[i]=arr[j];
i++;
}

}
}
//sort the list
for(int k=0;k<i;k++)
{
for(int j=0;j<i-1;j++)
{
if(new_arr[j]>new_arr[j+1])
{
int temp=new_arr[j];
new_arr[j]=new_arr[j+1];
new_arr[j+1]=temp;
}
}
}

//print the sorted list
printf("\n\nsorted list: \n");

for(int k=0;k<i;k++)
printf("\n%d",new_arr[k]);

return 0;
}


