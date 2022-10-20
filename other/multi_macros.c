#include <stdio.h>
#define MAKE_ARRAY_FUNCTION(FUNNAME, TYPE) \
TYPE FUNNAME(const TYPE*a, int n) \
{ \
    TYPE s = 0; \
    while(n>0) { \
        s += *a; \
        a++; \
        n--; \
    } \
    return s; \
}
MAKE_ARRAY_FUNCTION(int_array_sum, int);

int main()
{

    int c = 0;
    int a[] = {1,2,3,4};
    c = int_array_sum(a, 4);
    printf("%d\n",c);
}