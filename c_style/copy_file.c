#include <stdio.h>

int main(int argc, char **argv){
    if (argc < 3)
    {
        fprintf(stderr, "Few args\n");
        return 1;
    }

    FILE *from, *to;
    int c;
    from = fopen(argv[1],"r");
    if(!from)
    {
        perror(argv[1]);
        return 2;
    }
    to = fopen(argv[2],"w");

    if(!from)
    {
        perror(argv[2]);
        return 2;
    }
    while ((c = fgetc(from)) != EOF)
    {
        fputc(c, to);
    }
    fclose(from);
    fclose(to);
    return 0;
}