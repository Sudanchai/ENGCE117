#include <stdio.h>

int i;
int j;
int x;

int main()
{
    scanf("%d", &x);
    for (i = 0; i < x; i++)
    {
        j = i % 2;
        if(j != 0)
        {
            printf("%d\n", i );
        }
    }
}
