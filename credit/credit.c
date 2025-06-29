#include <cs50.h>
#include <stdio.h>
#include <string.h>
bool CheckIfValid(long credit);
int CalWithMulti(long cre);
int CalJustAdd(long cre);
void CheckWhichProvider(long credit);

int main(int argc, string argv[])
{
    bool valid = false;
    long credit = get_long("Number: ");

    valid = CheckIfValid(credit);

    if(valid)
        CheckWhichProvider(credit);
    else printf("INVALID\n");
}
void CheckWhichProvider(long credit)
{
        if((credit > 340000000000000  && credit <349999999999999) || (credit > 370000000000000  && credit <379999999999999)) //american express
        {
            printf("AMEX\n");
        }
        else if((credit > 5100000000000000  && credit <5199999999999909) || (credit > 5200000000000000  && credit <5299999999999909) || (credit > 5300000000000000  && credit <5399999999999909) || (credit > 5400000000000000  && credit <5499999999999999) || (credit > 5500000000000000  && credit <5599999999999999)) //Visa
        {
            printf("MASTERCARD\n");
        }
        else if(( credit > 4000000000000 && credit < 4999999999999) || ( credit > 4000000000000000 && credit < 4999999999999909))
        {
            printf("VISA\n");
        }
        else printf("INVALID\n");
}

bool CheckIfValid(long credit)
{
    if (((CalWithMulti(credit) + CalJustAdd(credit) ) % 10) == 0)
            return true;
    else return false;

}

int CalJustAdd(long cre)
{
    int digit = 0 ;
    int justAdd = 0 ;
    for(int i = 0 ; i < 16 ; i++ )
    {
    digit = cre % 10;
    justAdd += digit;
    cre = cre /100;
    }
    return justAdd;
}

int CalWithMulti(long cre)
{
      int digit2 = 0;
      int multiply = 0;
      cre = cre /10;
    for(int i = 0 ; i < 16 ; i++ )
    {
        digit2 = cre % 10;
        digit2 = 2*digit2;
        if (digit2 > 9)
            {
                //splitAndAdd
                int split = digit2 % 10;
                    digit2 = split + digit2/10;
            }

        multiply += digit2;
        cre = cre /100;

    }
        return multiply;
}
