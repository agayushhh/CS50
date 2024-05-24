#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
    int repeat=0;
    int f = strlen(argv[1]);
    for(int i=0;i<f-1;i++)
    {
        if(toupper(argv[1][i]) == toupper(argv[1][i+1]))
        {
           repeat++;
        }
    }
    if(argc == 1 || argc > 2 || repeat > 0)
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
        char a;
        int l=strlen(argv[1]);
        printf("ciphertext: ");
        for(int i=0;i<(l);i++)
        {
        if(isupper(s[i]))
        {
            a = toupper(argv[1][s[i]-'A']);
            printf("%c",a);
        }
        else if(islower(s[i]))
        {
            a = tolower(argv[1][s[i]-'a']);
             printf("%c",a);
        }
        else if(isblank(s[i]))
        {
            printf(" ");
        }
        else if(isalnum(s[i]))
        {
            printf("%c",s[i]);
        }
        else if(ispunct(s[i]))
        {
            printf("%c",s[i]);
        }

    }
     printf("\n");
    }
    return 0;
}


