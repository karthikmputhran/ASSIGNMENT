#include<stdio.h>
#include<string.h>
int main()
{
    int status;
    printf("enter the status(1-4)");
    scanf("%d",&status);
    switch(status)
    {
        case 1 : printf("order placed sucessfully");
                break;
        case 2 : printf("your food is being prepared");
                break;
        case 3 : printf("your order is out for delivery");
                break;
        case 4 : printf("Your order has been delivered. Enjoy your meal!");
                break;
        default:
        printf("invalid input");
    }
return 0;
}
