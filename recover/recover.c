#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // accepting only one commandlie argument
    if (argc != 2)
    {
        printf("fuck you and your mum, only one argument, exit code 1\n");
        return 1;
    }

    char *file = argv[1]; //file pointer named file is pointing at the file recieved from user

    FILE *fileptr = fopen(file , "r"); // open the file
    if(fileptr == NULL) // if file not opened inform the user
    {
        printf("fuck you and your mum, only one argument, exit code 2\n");
        return 2;
    }
    // creating a buffer of 512 byte size to put each block of the JPEG file in it
    uint8_t buffer[512];

}
