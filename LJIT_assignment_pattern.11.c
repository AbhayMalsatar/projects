#include <stdio.h>
int main()
{
    int i, j, a, c, k;
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
                    k = i + 1;
                    printf("%d ", k);
                }

                for (int j = 1; j <= i; j++)
                {
                    printf("%d ", k);
                }
                printf("\n");
            }
            printf("-----------------------------------------------------------------\n");
        }
    }
}
