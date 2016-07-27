#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

#define alpha_len 26

int vigenere(int ch, int rotate);
int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("oops! \n");
        return 1;
    }
    string key = argv[1];
    for (int n = 0; n < strlen(key); n++)
    {
        if ((key[n] >= '0') && (key[n] <= '9'))
        {
            printf("Sorry! Your key containt the number\n");
            return 1;
        }
    }
    string str=GetString();
    int j=0;
    for (int i = 0; i < strlen(str); i++) 
    {
        if(j>=strlen(key))
        {
            j=0;
        }
        printf("%c",vigenere(str[i],key[j]));
        if(isalpha(str[i]))
        {
            j++;
        }    
    }
    printf("\n");
}
int vigenere(int ch, int key)
{
    const char alpharray[2*alpha_len] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    const char alpharray1[2*alpha_len] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (islower(ch) && islower(key)) {
        return alpharray[ch-'a'+key-'a'];
    }
    else if(isupper(ch) && islower(key))
    {
        return alpharray1[ch-'A'+key-'a'];
    }
    if (islower(ch) && isupper(key)) {
        return alpharray[ch-'a'+key-'A'];
    }
    else if(isupper(ch) && isupper(key))
    {
        return alpharray1[ch-'A'+key-'A'];
    }
    else
    {
        return ch;
    }
}