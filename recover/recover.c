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
   int8_t buffer[512];
   while(fread(&buffer,sizeof(int8_t),1,input)!=0)
   {
        if (buffer[0]==0xff && buffer[1]==0xd8 && buffer[0]==0xff && (buffer[0]& 0xff) == 0xe0 )
        {
            FIL
        }
   }

}
