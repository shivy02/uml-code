#include <stdio.h>
void pFunction(int*);
    int main()
    {
        int i = 10;
        pFunction((&i)++);
    }
    void pFunction(int *p)
    {
        printf("%d\n", *p);
    }