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
  int count=0;
  int new = 0;
   int8_t buffer[512];
   while(fread(&buffer,1,512,input)==512)
   {
        if (buffer[0]==0xff && buffer[1]==0xd8 && buffer[0]==0xff && (buffer[0]& 0xff) == 0xe0 )
        {
            if(count>1)
            {
                fclose(img);
                count++;
                sprintf(fname,"%03i.jpg",count)
                FILE *img = fopen(fname,"w")
                fwrite(&buffer,1,512,img)
                new = 1;
            }
            else
            {
                count++;
                sprintf(fname,"%03i.jpg",count)
                FILE *img = fopen(fname,"w")
                fwrite(&buffer,1,512,img)
                new = 1;
            }




        }
   }

}
