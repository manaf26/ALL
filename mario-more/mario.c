#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>


void printSpace(void);

void printHashes(int x);

void printBlank(int y);

void PrintSecondHash(int z);

int main (int argc , string argv[])
{
    if (argc != 2)
         printf("USAGE: Number between 1-8\n");
    int R;
    do
    {
        //R =  get_int("inter the hight  ");
        R =  atoi(argv[1]);
    }while (R < 1 || R > 8 );

    int C = R;


    int blank = C - 1;
    int hash =  1;
    int z = hash;
    for(int i = 0 ; i < R ; i++)
    {
        printBlank(blank);

        printHashes(hash);

        blank--;

        printSpace();
        PrintSecondHash(hash);
        hash++;
        printf("\n");
    }


}
void printSpace(void)
{
    for(int j = 0 ; j < 2 ; j++)
    printf(" ");

}

void printHashes(int x)
{
    for(int j = 0 ; j < x ; j++)
    {
        printf("#");
    }

}
void printBlank(int y)
{
       for(int k = 0 ; k < y ; k++)
        {
            printf(" ");
        }
}

void PrintSecondHash(int z)
{
    for (int i = 0 ; i < z ; i++)
        printf("#");
}
