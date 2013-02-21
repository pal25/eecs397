#include <stdio.h>

void re_curse(int n)
{
    printf("%d \n", n++);
    re_curse(n);
}

int main(int argc, char** argv)
{
    re_curse(1); // Let the fun begin!
    return 0;
}
