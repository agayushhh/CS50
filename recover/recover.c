#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    printf("./recover recover_file : should be the cmd line prompt\n");
    return 1;

  }

  FILE *input = fopen(argv[1],"r");
  if (input == NULL)
  {
    printf("invalid file");
    return 1;
  }
   int512_t Buffer;
   fread(&buffer,sizeof(int512_t),)
}
