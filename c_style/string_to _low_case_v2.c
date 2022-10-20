#include <stdio.h>

int case_low(char c)
{
    if (c >= 'A' && c <= 'Z') return c + ('a' - 'A');
    else return c;
}

void string_to_low_case(char* _str)
{
    int i = 0;
    while (_str[i] != '\0')
    {
        _str[i] = case_low(_str[i]);
        ++i;
    }
}

void print_string(char* _str)
{
    int i = 0;
    do
    {
        printf ("%c", _str[i]);
        ++i;   
    } while (_str[i] != '\0');
    printf ("\n");
}

int main()
{
    printf("Type string:\n");
    char str[255];
    scanf("%s", str);
    string_to_low_case(str);
    printf("After conversation into low case:\n");
    print_string(str);

    return 0;
}