#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


int findValue(string input);
int main(void)
{
    string player1 = get_string("player1: ");
    string player2 = get_string("player2: ");
    for(int i = 0; player1[i]; i++)
    {
        player1[i] = toupper(player1[i]);
    }
    for(int i = 0; player2[i]; i++)
    {
        player2[i] = toupper(player2[i]);
    }
    int player1Score = findValue(player1);
    int player2Score = findValue(player2);

    if (player1Score > player2Score)
        printf("Player 1 wins!\n");
    else if (player1Score < player2Score)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");

}

int findValue(string input)
{
    int i = 0 ;
    int counter = 0;
    while (input[i] != '\0') // this while is to check each letter in the string
    {

        switch (input[i])
        {
        case 'A' : counter += 1; break;
        case 'B' : counter += 3; break;
        case 'C' : counter += 3; break;
        case 'D' : counter += 2; break;
        case 'E' : counter += 1; break;
        case 'F' : counter += 4; break;
        case 'G' : counter += 2; break;
        case 'H' : counter += 4; break;
        case 'I' : counter += 1; break;
        case 'J' : counter += 8;break;
        case 'K' : counter += 5;break;
        case 'L' : counter += 1;break;
        case 'M' : counter += 3;break;
        case 'N' : counter += 1; break;
        case 'O' : counter += 1;break;
        case 'P' : counter += 3;break;
        case 'Q' : counter += 10;break;
        case 'R' : counter += 1;break;
        case 'S' : counter += 1;break;
        case 'T' : counter += 1;break;
        case 'U' : counter += 1;break;
        case 'V' : counter += 4;break;
        case 'W' : counter += 4;break;
        case 'X' : counter += 8;break;
        case 'Y' : counter += 4;break;
        case 'Z' : counter += 10;break;

        }
        i++;
    }
    return counter;
}
