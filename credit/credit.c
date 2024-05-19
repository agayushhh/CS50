#include <cs50.h>
#include <stdio.h>
int main()
{
    long n = get_long("Number: ");
    int sum = 0;
    int sum2 = 0;
    long rsn = n;
    int gfn;
    int gsn;
    int msn;
    int a = rsn/1e16;
    int b = rsn/1e15;
    int c = rsn/1e12;

    if (a > 0)
    {
        printf("INVALID\n");
    }

    else if (b > 0)
    {
        for (int i = 0; i < 9; i++)
        {
            gfn = rsn % 10;
            sum2 = sum2 + gfn;
            rsn = rsn / 10;
            gsn = rsn % 10;
            if ((gsn * 2) >= 10)
            {
                msn = (2 * gsn) % 10;
                sum = sum + 1 + msn;
            }
            else
            {
                msn = gsn * 2;
                sum = sum + msn;
            }
            rsn = rsn / 10;
        }
        if ((sum + sum2) % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {

        printf("INVALID");

        }
    }

    else if (c > 0)
    {
        for (int i = 0; i < 7; i++)
        {
            gfn = rsn % 10;
            sum2 = sum2 + gfn;
            rsn = rsn / 10;
            gsn = rsn % 10;
            if ((gsn * 2) >= 10)
            {
                msn = (2 * gsn) % 10;
                sum = sum + 1 + msn;
            }
            else
            {
                msn = gsn * 2;
                sum = sum + msn;
            }
            rsn = rsn / 10;
        }
        if ((sum + sum2) % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
        printf("INVALID");
        }
    }

    else
    {
        printf("INVALID\n");
    }

    return 0;
}
