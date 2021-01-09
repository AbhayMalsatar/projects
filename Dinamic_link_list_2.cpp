#include <iostream>
#include <bits/stdc++.h>
int count_ind = 0;
using namespace std;
struct nord
{
    int data;
    struct nord *next;
} *First = NULL;

void insert_at_begin(int n)
{
    struct nord *t;
    t = new struct nord;
    t->data = n;
    if (First == NULL)
    {
        First = t;
        First->next = NULL;
        return;
    }

    t->next = First;
    First = t;
}

void insert_at_end(int n)
{
    struct nord *t, *temp;
    t = new struct nord;
    t->data = n;
    if (First == NULL)
    {
        First = t;
        First->next = NULL;
        return;
    }
    temp = First;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = t;
    t->next = NULL;
}

void Display_ele()
{
    struct nord *t;
    t = First;
    if (t == NULL)
    {
        printf("Link list is empty.\n");
        return;
    }
    printf("\n**********************************************************\n");
    printf("Elements : ");
    while (t->next != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("%d", t->data);
    printf("\n**********************************************************\n");
}

void Delete_at_beginning()
{
    struct nord *t;
    if (First == NULL)
    {
        printf("Link list is empty\n");
        return;
    }
    t = First->next;
    free(First);
    First = t;
    printf("Delete from beginning Successfully!!!\n");
}

void Delete_at_end()
{
    struct nord *t, *temp;
    int n;
    if (First == NULL)
    {
        printf("Link list is empty\n");
        return;
    }
    t = First;
    while (t->next != NULL)
    {
        temp = t;
        t = t->next;
    }
    temp->next = NULL;
    free(t);
    printf("Delete from beginning Successfully!!!\n");
}

int search_ele(struct nord *p, int key)
{
    if (First == NULL)
    {
        printf("Link list is empty\n");
    }

    while (p != NULL)
    {

        if (p->data == key)
        {
            return p->data;
        }
        else
        {
            count_ind++;
            p = p->next;
        }
    }
}

void sum_of_ele()
{
    int sum = 0;
    struct nord *t;
    t = First;
    if (First == NULL)
    {
        printf("Link list is empty\n");
        return;
    }
    while (t != NULL)
    {
        sum = sum + t->data;
        t = t->next;
    }
    printf("Sum of element: %d", sum);
}

void max_ele()
{
    if (First == NULL)
    {
        printf("Link list is empty\n");
        return;
    }
    int max_ele = -32768;
    struct nord *t;
    t = First;
    while(t != NULL)
    {
        if(t->data > max_ele)
        {
            max_ele = t->data;
        }
        t = t->next;
    }
    printf("Maximum element:  %d",max_ele);
}

void reverse_linklist(struct nord *t)
{
    if (First == NULL)
    {
        printf("Link list is empty\n");
        return;
    }
    if(t != 0)
    {
       reverse_linklist(t->next);
       printf("%d ",t->data);
    }
}
int main()
{
    int a, ele, key;
    int temp;
    while (1)
    {
        count_ind = 0;
        printf("\n---------------------------------------------------------------\n");
        printf("1. Insert element at the beginning\n");
        printf("2. Insert element at the end\n");
        printf("3. Display Link list\n");
        printf("4. Delete element from beginning\n");
        printf("5. Delete element from end\n");
        printf("6. Searching Element\n");
        printf("7. sum of element\n");
        printf("8. Find Maximum Number in link list\n");
        printf("9. reverse link list\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the Element:  ");
            scanf("%d", &ele);
            insert_at_begin(ele);
            break;
        case 2:
            printf("Enter the Element:  ");
            scanf("%d", &ele);
            insert_at_end(ele);
            break;
        case 3:
            Display_ele();
            break;
        case 4:
            Delete_at_beginning();
            break;
        case 5:
            Delete_at_end();
            break;
        case 6:
            printf("Enter the Element for checking:  ");
            scanf("%d", &key);
            temp = search_ele(First, key);
            if (temp == key)
            {
                printf("Key is Found");
                printf(" at %d index", count_ind + 1);
            }
            else
            {
                printf("Key is not found");
            }
            break;
        case 7:
            sum_of_ele();
        case 8:
             max_ele();
            break;
        case 9:
            printf("\n**********************************************************\n");
            printf("Reverse Link list: ");
            reverse_linklist(First);
            printf("\n**********************************************************\n");
            break;
        default:
            printf("please enter the right number");
            break;
        }
    }
}
