
#include <stdio.h>
#include "stack.h"

int main(int argc, char* argv[])
{
    int num;
    STACK hStack = stack_init_default();
    
    printf("Enter number of cases: \n");
    scanf("%d", &num);
    clear_keyboard_buffer();
    
    for(int i = 0; i < num; i++)
    {
        
        if(test_case_is_valid(hStack, i + 1))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}
