#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float findLetters(string s);
float findSenteces(string s);
float theEqation(int L , int S);
void control(float inx);
int main(void)
{
    string inputString = get_string("Text: ");
    int L = findLetters(inputString);
    int S = findSenteces(inputString);
    float index = theEqation(L , S);

    control(index);


}
float findLetters(string s)
{
    float letters = 0 ;
    float words = 0;
    int i = 0 ;
    while(s[i] != '\0')
    {
        if(isalpha(s[i]))
            letters++;
        if (isblank(s[i]))
             words++;
        i++;
    }
    words++;
    //printf("letters  %0.2f\n",letters);
   // printf("wordsL  %0.2f\n",words);
    return (letters/words)*100.0;
}

float findSenteces(string s)
{
    float sentences = 0 ;
    float words = 0 ;
    int i = 0 ;
    while(s[i] != '\0')
    {
        if( s[i] == '.' || s[i] == '!' || s[i] == '?')
            sentences++;
        else if (s[i] == ' ')
             words++;
        i++;
    }
    words++;
    //printf("sentences  %0.2f\n",sentences);
    //printf("words  %0.2f\n",words);
    return (sentences/words)*100.0;
}

float theEqation(int L , int S)
{
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}
void control(float inx)
{
    if (inx < 1)
        printf("Before Grade 1\n");
    else if (inx >= 1 && inx <2)
        printf("Grade 1\n");
    else if (inx >= 2 && inx <3)
        printf("Grade 2\n");
    else if (inx >= 3 && inx <4)
        printf("Grade 3\n");
    else if (inx >= 4 && inx <5)
        printf("Grade 4\n");
    else if (inx >= 5 && inx <6)
        printf("Grade 5\n");
    else if (inx >= 6 && inx <7)
        printf("Grade 6\n");
    else if (inx >= 7 && inx <8)
        printf("Grade 7\n");
    else if (inx >= 8 && inx <9)
        printf("Grade 8\n");
    else if (inx >= 9 && inx <10)
        printf("Grade 9\n");
    else if (inx >= 10 && inx <11)
        printf("Grade 10\n");
    else if (inx >= 11 && inx <12)
        printf("Grade 11\n");
     else if (inx >= 12 && inx <13)
        printf("Grade 12\n");
    else if (inx >= 13 && inx <14)
        printf("Grade 13\n");
    else if (inx >= 14 && inx <15)
        printf("Grade 14\n");
    else if (inx >= 15 && inx <16)
        printf("Grade 15\n");
    else if (inx >= 16 && inx <17)
        printf("Grade 16\n");
    else
        printf("Grade 16+\n");

}
