#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *f = fopen(argv[1],"r");
    if (f == NULL)
    {
        return 1;
    }
    unsigned char bytes[512];
    bool first_jpg = true;
    int x = 0;
    char filename[8];
    FILE *img = NULL;
    while(!feof(f))
    {
        fread(bytes,1,512,f);
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
        {
            if (first_jpg == true)
            {
                sprintf(filename, "%03i.jpg", x);
                img = fopen(filename, "w");
                fwrite(bytes,1,512,img);
                x++;
                first_jpg = false;
            }
            else if (first_jpg == false)
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", x);
                img = fopen(filename, "w");
                fwrite(bytes,1,512,img);
                x++;
            }
        }
        else
        {
            if (first_jpg == true)
            {
                continue;
                printf("Turn me into a jpeg!\n");
            }
        }
    }
}
