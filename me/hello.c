#include <stdio.h>
#include <string.h>
int main(){
    printf("What is your name ?  ");
    char name[100];
    gets(name);
    printf("Hello, %s, \n",name );
    return 0;
}
