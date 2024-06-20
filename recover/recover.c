#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover recover_file\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Invalid file\n");
        return 1;
    }

    int count = 0;
    int new = 0;
    FILE *img = NULL;
    char fname[8];
    uint8_t buffer[512];

    while (fread(&buffer, 1, 512, input) == 512)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if (count >= 1)
            {
                fclose(img);
            }


            sprintf(fname, "%03i.jpg", count);
            img = fopen(fname, "w");
            if (img == NULL)
            {
                printf("Could not create %s.\n", fname);
                fclose(input);
                return 1;
            }

            fwrite(&buffer, 1, 512, img);
            count++;
            new = 1;
        }
        else if (new == 0 && count >= 1)
        {
            
            fwrite(&buffer, 1, 512, img);
        }

        new = 0;
    }

    // Close any remaining files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(input);

    return 0;
}
