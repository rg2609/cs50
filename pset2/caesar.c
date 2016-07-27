#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

#define alpha_len 26

int caesar(int ch, int rotate);
int main(int argc, string argv[])
{
    if (argc < 2) {
        printf("Usage: caesar rotateN\n");
        return 1;
    }
    int key = atoi(argv[1]) % alpha_len;
    string str=GetString();

    for (int i = 0; i < strlen(str); i++) {
            printf("%c",caesar(str[i],key));
    }
    printf("\n");
}
int caesar(int ch, int key)
{
    const char alpharray[2*alpha_len] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    const char alpharray1[2*alpha_len] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (islower(ch)) {
        return alpharray[ch-'a'+key];
    }
    else if(isupper(ch))
    {
        return alpharray1[ch-'A'+key];
    }
    else
    {
        return ch;
    }
}