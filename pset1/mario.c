#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int n;
    do
    {
        printf("Height: ");
        n=GetInt();
        
    }while(n<0 || n>23);
    for(int i=1;i<=n;i++)
    {
        for(int k=n;k>i;k--)
        {
            printf(" ");
        }
        for(int k=0;k<i;k++)
        {
            printf("#");
        }
        printf("#\n");
    }
}