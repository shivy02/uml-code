#include <stdio.h>

int main(void) {

    int c;

    c = (getchar() != EOF);
    printf("%d\n", c);

    int a = EOF;
    printf("%d", a);

    return 0;
}