#include <cs50.h>
#include <stdio.h>

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
 }

int score(string s)
{
    int i=0;
    while(s[i]!=\0)
    
}
