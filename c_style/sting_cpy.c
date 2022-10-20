#include <stdio.h>

void str_cpy(char* dest, const char* src)
{
    while(*src)
    {
        *dest = *src;
        ++dest;
        ++src;
    }
    *dest = 0;
}

void str_cpy_fail(char* dest, const char* src)
{
    while((*dest++ = *src++))
    {
        printf("%c",*src);
    }
        printf("\n");
}

int main(){
    char a[] = "hello, moto";
    char b[40];
    str_cpy_fail(b,a);
    printf("%s\n",b);
}