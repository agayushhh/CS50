#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    string s = get_string("Text: ");
    int punc = 0;
    int gap = 0;
    int sent = 0;
    int words = 1;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '.'|| s[i] == '?' || s[i] == '!' )
        {
            sent++;
            punc++;
        }
        else if (s[i] == ',' || s[i] == '"' || s[i] == '\'' || s[i] == ';' || s[i] == ':')
        {
            punc++;
        }
        else if (s[i] == ' ')
        {
            gap++;
            words++;
        }
    }
    float L = ((float)(length - gap - punc) / words) * 100;
    float S = ((float)sent / words) * 100;
    float index1 = 0.0588 * L - 0.296 * S - 15.8;
    int index= round(index1);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}
