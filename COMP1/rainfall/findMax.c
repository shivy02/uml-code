#include <stdio.h>
#include <stdlib.h>

typedef struct cuboid{
     float length;
     float width;
     float height;

}Cuboid;

int findMaxIndex(int *array, int size);
float cuboidvolume(cuboid cube);

int main(void) {
    int n, i, *ptr;

    struct Cuboid cube;

    cube.length = 3.5;
    cube.width = 2.25;
    cube.height = 3.0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));
 
    //if memory cannot be allocated
    if(ptr == NULL)                     {
        printf("Error! memory not allocated.");
        exit(0);
    }

    for(i = 0; i < n; ++i){
        ptr[i] = rand();
    }
  
    printf("Max index is: %d", findMaxIndex(ptr, n));
    // deallocating the memory
    free(ptr);
}

int findMaxIndex(int *array, int size){
    
    int i = 0;
    int max, maxIndex;
 
    maxIndex = i;
    max = array[i];
    for(i = 0; i < size; i++){
        if(array[i] > max)
            maxIndex = i;
            max = array[i];
    }

    return maxIndex;
}


float cuboidvolume(cuboid cube){
    
    float volume;
    volume = cube.length * cube.width * cube.height;
    return volume;

}