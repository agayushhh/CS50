#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main()
{
    string s = get_string("Text: ");
    int punc=0;
    int gap=0;
    int sent=0;
    for(int i=0; i<strlen(s);i++)
    {
        if(s[i]==".")
        {
            sent++;
            punc++;
        }
        else if(s[i]==",")
        {
            punc++;
        }
        else if(s[i]==" ")
        {
            gap++;
        }
    }
    int L= (strlen(s)-gap-punc)/100;
    int s= sent/100;
    int index = 0.0588 * L - 0.296 * S - 15.8;
    
}
