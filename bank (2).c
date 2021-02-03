#include <stdio.h>
#include <string.h>

#define Max 100

int Account_holder_num = 0;
int count = 0;
int count1 = 0;

// struct of account details

typedef struct Account_holder_info
{
    char name[Max];
    long account_num;
    float bank_balance;
    int password;
} ban;

ban b[Max];

// auto generate account number

long generate_account_num()
{
    static long account_num = 1001;
    return account_num++;
}

// add Account holder details

void addBanker(ban *b, char name[], int password, float bank_balance)
{

    b->account_num = generate_account_num();
    strcpy(b->name, name);
    b->bank_balance = bank_balance;
    b->password = password;
    puts("\nYour Details Added Successfully");

    printf("Your account number Is:  %ld\n", b->account_num);
    Account_holder_num++;
    count1++;
}

// display all account details

void display(ban b)
{
    printf("----------------------------------\n");

    static int i = 0;
    if (i >= Account_holder_num)
    {
        i = 0;
    }
    printf("%d. Employee Details Are: \n", ++i);

    printf("Account number of Account_holder is:  %ld\n", b.account_num);
    printf("Name Of Account_holder             :  %s\n", b.name);
    printf("Balance  is                        :  %.2f\n", b.bank_balance);
    printf("password of the Account_holder     :  ******\n");

    printf("----------------------------------\n");
}

// checking your writting account number is true or note

int searchAccount_holder(ban b[], long account_num)
{
    int i;
    int flag = 0;

    for (i = 0; i < Account_holder_num; i++)
    {
        if (b[i].account_num == account_num)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

// check password is wrong or not

int check_password(ban b[], int password, long account_num)
{
    int i;
    int flag = 0;
    for (i = 0; i < Account_holder_num; i++)
    {
        if (b[i].password == password && b[i].account_num == account_num)
            flag = 1;
    }
    return flag;
}

// to check if two account holder has not same password

int check_same_pass(ban b[], int password)
{
    int i;
    int flag = 0;
    for (i = 0; i < Account_holder_num; i++)
    {
        if (b[i].password == password)
        {
            flag = 1;
        }
    }

    return flag;
}

// change password

void change_password(ban b[], long account_num, int password, int password1)
{
    int i, check_pass;
    int sea_Account_holder = searchAccount_holder(b, account_num);

    if (sea_Account_holder == 0)
    {
        printf("\nAccount number is not matched\n");
    }
    else
    {
    lable:
        check_pass = check_password(b, password1, account_num);

        if (check_pass == 0)
        {
            printf("\nenter your old  password correct\n");
            count++;
            printf("Enter your password again: ");
            scanf("%d", &password1);
            if (count == 9)
            {
                printf("\nWarning : now you can enter your password only one time\n");
            }
            else if (count > 10)
            {
                exit(1);
            }
            goto lable;
        }
        else
        {
            for (i = 0; i < Account_holder_num; i++)
            {
                if (b[i].account_num == account_num)
                {
                    b[i].password = password;
                }
            }
            printf("\nYour password is modified\n");
        }
    }
}

// deposit money

void Deposite_money(ban b[], float money, long account_num)
{
    int i;
    int sea_Account_holder = searchAccount_holder(b, account_num);

    if (sea_Account_holder == 0)
    {
        printf("\nAccount number is not matched\n");
    }
    else
    {
        for (i = 0; i < Account_holder_num; i++)
        {
            if (b[i].account_num == account_num)
            {
                b[i].bank_balance += money;
            }
        }
        printf("\nyour Balance is added successfully\n");
    }
}

// withdraw money

void widthdraw_money(ban b[], float money, long account_num, int password)
{
    int i;
    int sea_Account_holder = searchAccount_holder(b, account_num);
    int check_pass;

    if (sea_Account_holder == 0)
    {
        printf("\nAccount number is not matched\n");
    }
    else
    {
    lable:
        check_pass = check_password(b, password, account_num);

        if (check_pass == 0)
        {
            printf("\nenter your password correct\n");
            count++;
            printf("Enter your password again: ");
            scanf("%d", &password);
            if (count == 9)
            {
                printf("\nWarning : now you can enter your password only one time\n");
            }
            else if (count > 10)
            {
                exit(1);
            }
            goto lable;
        }
        else
        {
            for (i = 0; i < Account_holder_num; i++)
            {
                if (b[i].account_num == account_num)
                {
                    float l = b[i].bank_balance - money;
                    if (l < 0)
                    {
                        printf("\nYou have not enough money\n");
                    }
                    else
                    {
                        b[i].bank_balance = l;
                        printf("\nyour money is withdraw successfully\n");
                    }
                }
            }
        }
    }
}

// Remove your account

void removeAccount_holder(ban b[], long account_num, int password1)
{
    int i;
    int flag = 0;
    int sea_Account_holder = searchAccount_holder(b, account_num);
    int check_pass;
    int index = (int)account_num - 1001;

    if (sea_Account_holder == 0)
    {
        printf("\nAccount number is not matched\n");
    }
    else
    {
    lable:
        check_pass = check_password(b, password1, account_num);

        if (check_pass == 0)
        {
            printf("\nenter your password correct\n");
            count++;
            printf("Enter your password again: ");
            scanf("%d", &password1);
            if (count == 9)
            {
                printf("\nWarning : now you can enter your password only one time\n");
            }
            else if (count > 10)
            {
                exit(1);
            }
            goto lable;
        }
        else
        {
            for (i = index; i < Account_holder_num; i++)
            {
                {
                    b[i] = b[i + 1];
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                printf("\nyour account was removed successfully\n");
                Account_holder_num--;
            }
        }
    }
}

// search account

void search_Account_holder(ban b[], long account_num)
{
    int i;
    int sea_Account_holder = searchAccount_holder(b, account_num);

    if (sea_Account_holder == 0)
    {
        printf("\nAccount number is not matched\n");
    }
    else
    {
        for (i = 0; i < Account_holder_num; i++)
        {
            if (b[i].account_num == account_num)
            {
                printf("\n %c Employee Details Are: \n", 16);

                printf("Account number of Account holder is:  %ld\n", b[i].account_num);
                printf("Name Of Account holder             :  %s\n", b[i].name);
                printf("Balance  is                        :  %.2f\n", b[i].bank_balance);
                printf("password of the Account holder     :  ******\n");

                printf("----------------------------------\n");
            }
        }
    }
}

// Transport Money in another account

void transport_money(ban b[], int password, long account1, long account2, float money)
{
    int i;
    int j;
    int sea_Account_holder1 = searchAccount_holder(b, account1);
    int sea_Account_holder2 = searchAccount_holder(b, account2);
    int check_pass;

    if (sea_Account_holder1 == 0)
    {
        printf("\nAccount number is not matched\n");
    }
    else if (sea_Account_holder2 == 0)
    {
        printf("\nAccount number is not matched\n");
    }
    else
    {
    lable:
        check_pass = check_password(b, password, account1);

        if (check_pass == 0)
        {
            printf("\nenter your password correct\n");
            count++;
            printf("Enter your password again: ");
            scanf("%d", &password);
            if (count == 9)
            {
                printf("\nWarning : now you can enter your password only one time\n");
            }
            else if (count > 10)
            {
                exit(1);
            }
            goto lable;
        }
        else
        {
            for (i = 0; i < Account_holder_num; i++)
            {
                if (b[i].account_num == account1)
                {
                    float l = b[i].bank_balance;
                    l -= money;
                    if (l < 0)
                    {
                        printf("\nYou have not enough money to transport\n");
                    }
                    else
                    {
                        b[i].bank_balance = l;
                    }
                }
            }
            for (j = 0; j < Account_holder_num; j++)
            {
                if (b[j].account_num == account2)
                {
                    b[j].bank_balance += money;
                }
            }
            printf("\nTransport Money Successfully\n");
        }
    }
}

void main()
{
    int i;
    long account_num, account_num1, account_num2, account_num3, account_num4, account_num5, account_num6;
    int Account_holder_choice, cha_password, old_password, password, password1, Account_holder_password, password2, check_pass;
    float Account_holder_balance, Width_money, Account_holder_balance11, money;
    char Account_holder_name[Max];

    printf("*---------Welcome in HOMESTAND Bank---------*\n");
    printf("\nYour Pravicy is our duty\n\n");

    while (1)
    {
        printf("\n--------------------------------------------------");
        printf("\n1. Add Account holder Details\n");
        printf("2. Display Account holder Details\n");
        printf("3. Change password\n");
        printf("4. Deposit your money\n");
        printf("5. withdraw your money\n");
        printf("6. Remove Account holder Details\n");
        printf("7. search Account holder Details\n");
        printf("8. Transport Your Money In Another Account\n");
        printf("0. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &Account_holder_choice);

        switch (Account_holder_choice)
        {
        case 1:
            printf("\n*---------------------Basic Instruction for creating account---------------------*\n");
            printf("\n %c Please enter first deposit maximum money 1000 , so we can open your account\n", 16);
            printf(" %c please Make Your password in interger\n", 16);
            printf(" %c Please Remember your password if you Enter password wrong more than 10 Session will be expaired\n", 16);

            printf("\nEnter Your Name:  ");
            fflush(stdin);
            gets(Account_holder_name);
            printf("Enter Your password :  ");
            scanf("%d", &Account_holder_password);
            check_pass = check_same_pass(b, Account_holder_password);
            while (check_pass == 1)
            {
                printf("Please Reenter your password: ");
                scanf("%d", &Account_holder_password);
                check_pass = check_same_pass(b, Account_holder_password);
            }
            printf("Enter your first deposit money: ");
            scanf("%f", &Account_holder_balance11);
            while (Account_holder_balance11 < 1000)
            {
                printf("Please Enter deposit money greater than & equal to 1000: ");
                scanf("%f", &Account_holder_balance11);
            }
            addBanker(&b[Account_holder_num], Account_holder_name, Account_holder_password, Account_holder_balance11);

            break;
        case 2:
            if (count1 == 0)
            {
                printf("\nPlease First enter Account_holder details\n");
            }
            else
            {
                for (i = 0; i < Account_holder_num; i++)
                {
                    display(b[i]);
                }
            }

            break;

        case 3:
            if (count1 == 0)
            {
                printf("\nPlease First enter Account_holder details\n");
            }
            else
            {
                printf("\nEnter your account number:  ");
                scanf("%ld", &account_num);
                printf("Enter your old password:  ");
                scanf("%d", &old_password);
                printf("Enter your new password: ");
                scanf("%d", &cha_password);
                change_password(b, account_num, cha_password, old_password);
            }
            break;

        case 4:
            if (count1 == 0)
            {
                printf("\nPlease First enter Account_holder details\n");
            }
            else
            {
                printf("\nEnter your account number: ");
                scanf("%ld", &account_num1);
                printf("Enter your money:  ");
                scanf("%f", &Account_holder_balance);
                Deposite_money(b, Account_holder_balance, account_num1);
            }
            break;

        case 5:
            if (count1 == 0)
            {
                printf("\nPlease First enter Account_holder details\n");
            }
            else
            {
                printf("\nEnter your account number: ");
                scanf("%ld", &account_num2);
                printf("Enter your money:  ");
                scanf("%f", &Width_money);
                printf("\nEnter your password: ");
                scanf("%d", &password);

                widthdraw_money(b, Width_money, account_num2, password);
            }
            break;

        case 6:
            if (count1 == 0)
            {
                printf("\nPlease First enter Account_holder details\n");
            }
            else
            {
                printf("\nEnter your account number: ");
                scanf("%ld", &account_num3);
                printf("\nEnter your password: ");
                scanf("%d", &password1);
                removeAccount_holder(b, account_num3, password1);
            }
            break;

        case 7:
            if (count1 == 0)
            {
                printf("\nPlease First enter Account_holder details\n");
            }
            else
            {
                printf("\nEnter your account number: ");
                scanf("%ld", &account_num4);
                search_Account_holder(b, account_num4);
            }
            break;

        case 8:
            if (count1 == 0)
            {
                printf("\nPlease First enter Account_holder details\n");
            }
            else if (count1 == 1)
            {
                printf("\nPlease Enter one another account\n");
            }
            else
            {
                printf("Enter your account number: ");
                scanf("%ld", &account_num5);
                printf("Enter account number which in transport money: ");
                scanf("%ld", &account_num6);
                printf("Enter money: ");
                scanf("%f", &money);
                printf("Enter your password: ");
                scanf("%d", &password2);

                transport_money(b, password2, account_num5, account_num6, money);
            }
            break;

        case 0:
            printf("\n*----------thank you for visiting----------*\n");
            exit(0);
            break;

        default:
            printf("Please enter choice correct\n");
            break;
        }
    }
    getch();
}
