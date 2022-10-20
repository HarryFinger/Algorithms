#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
    int a, b ,c;
    char str[50];
    FILE *f;
    f = fopen(argv[1],"r");
    if(!f)
    {
        perror(argv[1]);
        exit(1);
    }
    fgets(str, sizeof(str),f);
    
    sscanf(str, "%d%d%d", &a, &b, &c);

    printf("%d\n", (a+b+c));
    return 0;
}