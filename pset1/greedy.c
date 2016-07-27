#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int c=0;
    float no;
    int n;
    printf("O hai! ");
    do{
        printf("How much change is owed?\n");
        no=GetFloat();
        n=100*no;
    }
    while(n<1);
    if(n>=25)
    {
        //printf("n=%d",n);
        c+=n/25;
        n=n%25;
        //printf("1n=%d c=%d\n",n,c);
    }
    if(n>=10)
    {
        c+=n/10;
        n=n%10;
        //printf("2n=%d c=%d\n",n,c);
    }
    if(n>=5)
    {
        c+=n/5;
        n=n%5;
        //printf("3n=%d c=%d\n",n,c);
    }
    if(n!=0)
    {
        c+=n;
       //printf("4n=%d c=%d\n",n,c);
    }
    printf("%d\n", c);
}