#include<stdio.h>
#include<cs50.h>

int main(void)
{
    printf("minutes: ");
    int n=GetInt();
    int b=n*12;
    printf("bottles: %d\n",b);
}