#include<cstdio>
int num;
void power(int p)
{
    while(num<p){
        num*=2;
    }
}
int main(void)
{
    int card;
    while(~scanf("%d",&card)){
        if(card==0)break;
        num=1;
        power(card);
        num/=2;
        num=card-num;
        num*=2;
        {
            if(card!=1)printf("%d\n",num);
            else printf("1\n");
        }
    }
    return 0;
}
