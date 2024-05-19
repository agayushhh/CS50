#include <cs50.h>
#include <stdio.h>
int main()
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n <= 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = (n - 1) - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
    return 0;
}
