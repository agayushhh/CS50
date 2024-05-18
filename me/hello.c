#include <cs50.h>
#include <string.h>
int main(){
    string name= get_string("What is your name ?  ");
    printf("Hello, %s, \n",name );
    return 0;
}
