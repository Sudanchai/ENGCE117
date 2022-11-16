#include <stdio.h>

int customer;
int request = 1000;
int main()
{
    while(customer < request)
    {
        printf("Check promotion\n");
        printf("voucher\n");
        customer++;
        printf("customer increase%d\n\n", customer );
    }
}
