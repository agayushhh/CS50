#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main(int argc, string argv[])
{
    if(strlen(argv[1]) !=26)
    {
        printf("Usage: Key should be of 26 Character\n");
        return 1;
    }
    else if(isblank(argv[1]))
    {
        printf("Usage: ./substitution Key\n");
        return 1;
    }
}
