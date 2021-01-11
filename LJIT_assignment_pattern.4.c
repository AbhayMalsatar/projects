#include<stdio.h>
int main()
{
    int i ,j, k, a, b, c;
    while(1)
    {
        printf("\n1. continue\n");
        printf("0. exit\n");
        printf("Enter Your Choice:  ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("please Enter same size of row & column\n");
            printf("Enter the row:  ");
            scanf("%d",&a);
            printf("enter the column:  ");
            scanf("%d",&b);
            while(a != b)
            {
                printf("please Enter the Right row:  ");
                scanf("%d",&a);
                printf("Please Enter the right column:  ");
                scanf("%d",&b);
            }
            printf("-----------------------------------------------------------------\n");
            for(i = 0;i < a; i++)
            {
                for(j = 0;j < b; j++)
                {
                    k = 1;
                    if(j<=i) {
                        printf("%d ",i+1);
                    }
                    else {
                        printf(" ");
                    }

                }
                printf("\n");
            }
            printf("-----------------------------------------------------------------\n");
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("please Enter the right number");
            break;

        }
    }
}

