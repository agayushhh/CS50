#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main()
{
    string s = get_string("Text: ");
    int punc = 0;
    int gap = 0;
    int sent = 0;
    int words = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '.')
        {
            sent++;
            punc++;
        }
        else if (s[i] == ',')
        {
            punc++;
        }
        else if (s[i] == ' ')
        {
            gap++;
            words++;
        }
    }
    float L = ((strlen(s) - gap - punc) / words) * 100;
    float S = (sent / words) * 100;
    int index = 0.0588 * L - 0.296 * S - 15.8;
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}
