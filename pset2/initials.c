#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string str=GetString();
    for(int i=0;i<strlen(str);i++)
    {
        if(i==0)
        {
            printf("%c",toupper(str[i]));
        }
        if(isspace(str[i]))
        {
            printf("%c",toupper(str[i+1]));
        }
    }
    printf("\n");
}
