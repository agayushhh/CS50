#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void convert(string s[]);
int main(int argc, string argv[])
{
    if(argc == 1)
    {
        printf("Usage: ./substitution Key\n");
        return 1;
    }

    else if(strlen(argv[1]) !=26)
    {
        printf("Usage: Key should be of 26 Character\n");
        return 1;
    }
    else if ((argc == 2) && strlen(argv[1]) ==26 )
    {
        string s = get_string("Plaintext: ");
        convert(s);
    }
    return 0;
}

void convert(string s[])
{
    char a;
    for(int i=0,l=strlen(argv[1]);i<l;i++)
    {
        if(isupper(s[i]))
        {
            
        }
    }
}
