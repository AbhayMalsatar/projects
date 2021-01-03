#include<stdio.h>
int main()
{
    int units,a;
    float ucharge, fcharge, gtax, meter_rent = 25.0, total;
    printf("Welcome in the program of calculation of electrical bill\n");
    while(1)
    {
        printf("1 - calculate electrical bill\n");
        printf("0 - exit\n");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            printf("*********************************************************\n");
            printf("units must be none Zero positive intger\n");
            printf("\nEnter the unit: ");
            scanf("%d",&units);
            while(units <= 0)
            {
                printf("please renter the correct unit: ");
                scanf("%d",&units);
            }
            /*calculate the unit charges */
            if(units <= 50)
            {
                ucharge = 0.5 * units;
            }
            else if(units <= 100)
            {
                ucharge = 50*0.5 + (units - 50)*0.75;
            }
            else if(units <=200)
            {
                ucharge = 50*0.5 + 50*0.75 + (units - 100)*1.00;
            }
            else
            {
                ucharge = 50*0.5 + 50*0.75 + 100*1.00 + (units - 200)*1.50;
            }
            /* calculate the fuel charge and government charge */
            fcharge = ucharge*0.40;
            gtax = 0.10*(ucharge + fcharge);
            /* calculate total bill */
            total = ucharge + fcharge + gtax + meter_rent;
            printf("total bill = %.2f",total);
            printf("\n*********************************************************\n");
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("please enter the write number");
            break;
        }
    }
}
