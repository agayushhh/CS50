#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int value[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int score(string s);

int main()
 {
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    if(score(player1)>score(player2))
    {
        printf("Player 1 wins!\n");
    }
    if(score(player1)<score(player2))
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
 }

int score(string s)
{

    int sum=0;
    for(int i=0; i<strlen(s); i++)
    {
    s[i]= toupper(s[i]);
    sum = sum + value[s[i]-'A'];

    }
    return sum;

}
