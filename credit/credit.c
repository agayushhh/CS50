#include <cs50.h>
#include <stdio.h>
int main()
{
    long n = get_long("Number: ");
    int sum=0;
    long rsn = n;;
    int gsn;
    int msn;
    if ( rsn/1e14 > 0){
    for(int i=0;i<9;i++)
    {
        rsn= rsn/10;
        gsn=rsn%10;
        if((gsn*2)>=10)
        {
            msn=(2*gsn)%10;
            sum = sum + 1 + msn;
        }
        else
        {
            msn = gsn*2;
            sum = sum + msn;
        }
        rsn= rsn/10;
    }
    }
    else if (rsn/1000>0)
    {

    }

}
