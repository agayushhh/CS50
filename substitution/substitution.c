#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int repeat(string pass, int f);

int main(int argc, string argv[])
{
    string pas = argv[1];
    int f = strlen(argv[1]);
    int repeat2 = repeat(pas,f);

    if(argc == 1 || argc > 2 || repeat2 >=2 )
    {
        printf("Usage: ./substitution Key\n");
        return 1;
    }

    else if(strlen(argv[1]) !=26)
    {
        printf("Usage: Key should be of 26 Character\n");
        return 1;
    }
    else if ((argc == 2) && strlen(argv[1]) == 26 )
    {
        string s = get_string("Plaintext: ");
        char a;
        int l=strlen(s);
        printf("ciphertext: ");
        for(int i=0; i < l; i++)
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
        else if(s[i] == '\'' || s[i] == '"'|| s[i] == '!' || s[i] == ',' || s[i] == '.' )
        {
            printf("%c",s[i]);
        }

        }
     printf("\n");
    }
    return 0;
}

int repeat(string pass, int f)
{
    int repeat1 = 0;
     for(int i=0;i<f;i++)
    {
        for(int j=0;j<f;j++)
        {
        if(toupper(pass[i]) == toupper(pass[j]))
        {
           repeat1++;
        }

        }
        if(repeat1>1)
        {
            return repeat1;
        }
        else
        {
            repeat1=0;
        }
    }
    return repeat1;
}


