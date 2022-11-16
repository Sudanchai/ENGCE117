#include <stdio.h>

int money;
int prise = 100000;
int max = 10000000;
int main()
{
    printf("stock\n");
    while(money < max)
    {
        printf("order ");
        money=money+prise;
        printf("delivery ");
        printf("%d$\n",money);
    }
    return 0;
}
