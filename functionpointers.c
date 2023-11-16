#include <stdio.h>

void f1(int var)
{
    printf("this is f1 and var is: %d\n", var);
}

void f2(int var)
{
    printf("this is f2 and var is: %d\n", var);
}

void f3(int var)
{
    printf("this is f3 and var is: %d\n", var);
}

int main()
{
    /* define an array full of function pointers 
       to the above functions, that take an `int` as 
       their only argument */
    void (*pf[3])(int);
    pf[0] = f1;
    pf[1] = f2;
    pf[2] = f3;

    int c = 0;
    while(c < 3)
    {
        /* call the functions using the function pointers
           of the array at index `c` with `c` as an argument */
        (*pf[c]) (c);
        ++c;
    }

    return 0;
}
