#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
string convertTolower(string s);
 void encrypt(string key , string plain);
const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const  string alphabetLower = "abcdefghijklmnopqrstuvwxyz";
bool validate(string key);
bool CheckForDuplicate(string s);
bool CheckForNumbers(string s);
int control(string s);
string lKey(string s);
char cipher[100] ;
int main(int argc , string argv[])
{
                      // "XQNPOMAFTRHLZGECYJIUWSKDVB"
    string key      = argv[1];

    if (argc != 2)
    {
        printf("Usage : ./program Key\n");
        return 1;
    }

    if (validate(key))
        {
            string plain = get_string("Text  : ");
            encrypt(key,plain);
            //printf("Text  : %s\n",plain);
            printf("ciphertext: %s\n",cipher);
        }
    else return 1;



}

string lKey(string s)
{
    char lowerKey[26];
    strcpy (lowerKey, s);
    for (int z = 0; z < lowerKey[z] ; z++)
        {
          lowerKey[z] = tolower(s[z]);
        }
     string Slowerkey   = malloc(strlen(lowerKey) + 1); ;
     strcpy(Slowerkey,lowerKey);
    return Slowerkey;

}
 void encrypt(string key , string plain)
 {
    string lowerKey =lKey(key);
        int i = 0 ;

    while(plain[i] != '\0') //check the whole plain text
    {

        //check if lower or upper
        //if upper search here and substitute
        if (isupper(plain[i]))
        {
            int j = 0;
            while(plain[i] != alphabet[j]) // the first char of plain = which char of alphabet
                {
                   j++;
                }
            cipher[i] = key[j];
        }
        //if lower search here and substite
        else if(islower(plain[i]))
        {
            int t = 0 ;
            while(plain[i] != alphabetLower[t]) // the first char of plain = which char of alphabet
                {
                   t++;
                }
            cipher[i] = lowerKey[t];
        }
        else
        {
            cipher[i] = plain[i];
        }

        i++; //check the next char
    }
    //cipher[0] = key[j];

 }
bool CheckForDuplicate(string s)
{
    int frequency[26] = {0}; // Initialize all elements to 0

//char str[] = "YOURSTRING"; // Replace with your string

for(int i = 0; s[i] != '\0'; i++) {
    int index = s[i] - 'A'; // Calculate index
    frequency[index]++; // Increment the frequency

    // Check for duplicates
    if(frequency[index] > 1) {
        //printf("Duplicate found: %c\n", s[i]);
        return false;
    }
}
return true;

}

bool CheckForNumbers(string s)
{
    for(int i = 0 ; i < 26 ; i++)
    {
        if(!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}
bool validate(string key)
{
       if (strlen(key) < 26)
    {
        printf("key must be at least 26 chars\n");
        return false;
    }
    else if (strlen(key) > 26)
    {
        printf("key must be no longer 26 chars\n");
        return false;
    }
    else if (!CheckForDuplicate(key))
    {
        printf("Duplicates in the key Found\n");
        return false;
    }
    else if(!CheckForNumbers(key))
    {
        printf("numbers in the key Found\n");
        return false;
    }
    return true;
}
