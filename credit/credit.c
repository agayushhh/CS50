#include <cs50.h>
#include <stdio.h>
void AMEX(sum,sum2,rsn,m)
{
     int gfn;
    int gsn;
    int msn;
    for (int i = 0; i < m; i++)
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
            printf("AMEX\n");
        }
        else
        {

        printf("INVALID\n");

        }
}
void VISA(sum,sum2,rsn,m)
{
    int gfn;
    int gsn;
    int msn;
      for (int i = 0; i < m; i++)
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

        printf("INVALID\n");

        }
}
void Mastercard(sum,sum2,rsn,m)
   {
    int gfn;
    int gsn;
    int msn;
     for (int i = 0; i < m; i++)
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
            printf("MASTERCARD\n");
        }
        else
        {

        printf("INVALID\n");

        }
}
int main()
{

    long n = get_long("Number: ");
    int sum = 0;
    int sum2 = 0;
    long rsn = n;
    int a = rsn/1e16; //to check 17 digit number
    int b = rsn/1e15; //to check 16 digit number
    int b1= rsn%1000000000000000;
    int c = rsn/1e14; //to check 15 digit number
    int c1 = rsn%100000000000000;
    int d = rsn/1e13; //to check 14 digit number
    int e = rsn/1e12; //to check 13 digit number

   if (a > 0)
    {
        printf("INVALID\n");
    }

    else if (b > 0)
    {
        if ( (b + b1)==51 ||(b + b1)==52 ||(b + b1)==53 ||(b + b1)==54 ||(b + b1)==55)
        {
            Mastercard(sum,sum2,rsn,9);
        }

        else if(b==4)
        {
           VISA(sum,sum2,rsn,9);
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else if(c>0)
    {
        if( (c+c1)==34 || (c+c1)==37)
        {
            AMEX(sum,sum2,rsn,8);
        }
         else
         {
            printf("INVALID\n");
         }

    }

    else if(d>0)
    {
        printf("INVALID\n");
    }

    else if(e>0)
    {
        if(e==4)
        {
            VISA(sum,sum2,rsn,7);
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
    return 0;
}
