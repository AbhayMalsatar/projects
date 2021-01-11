#include <stdio.h>
int main()
{
    int i, j, a, c, b;
    while (1)
    {
        printf("\n1. continue\n");
        printf("0. exit\n");
        printf("Enter Your Choice:  ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the row:  ");
            scanf("%d", &a);
            while (a <= 0)
            {
                printf("please Enter the Right row:  ");
                scanf("%d", &a);
            }
            printf("-----------------------------------------------------------------\n");
            for (int i = 0; i < a; i++)
            {
                for (int j = a; j >= i + 2; j--)
                {
                    printf("  ");
                }
                for (int j = 0; j <= i; j++)
                {
                    printf("* ");
                }

                for (int j = 1; j <= i; j++)
                {
                    printf("* ");
                }
                printf("\n");
            }
            printf("-----------------------------------------------------------------\n");
        }
    }
}
