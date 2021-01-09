#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct nord
{
    int data;
    struct nord *next;
}*First = NULL;

void insert_at_begin(int n)
{
    struct nord *t;
    t = new struct nord;
    t->data = n;
    if(First == NULL)
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
   struct nord *t ,*temp;
   t = new struct nord;
   t->data = n;
   if(First == NULL)
   {
       First = t;
       First->next = NULL;
       return;
   }
   temp = First;
   while(temp->next != NULL)
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
    if(t == NULL)
    {
        printf("Link list is empty.\n");
        return;
    }
    printf("\n**********************************************************\n");
    printf("Elements : ");
    while(t->next != NULL)
    {
        printf("%d ",t->data);
        t = t->next;
    }
    printf("%d",t->data);
    printf("\n**********************************************************\n");
}

void Delete_at_beginning()
{
    struct nord *t;
    if(First == NULL)
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
    struct nord *t ,*temp;
    int n;
    if(First == NULL)
    {
        printf("Link list is empty\n");
        return;
    }
    t = First;
    while(t->next != NULL)
    {
        temp = t;
        t = t->next;
    }
    temp->next = NULL;
    free(t);
    printf("Delete from beginning Successfully!!!\n");
}


int main()
{
    int a ,ele;
    while(1)
    {
        printf("\n1. Insert element at the beginning\n");
        printf("2. Insert element at the end\n");
        printf("3. Display Link list\n");
        printf("4. Delete element from beginning\n");
        printf("5. Delete element from end\n");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            printf("Enter the Element:  ");
            scanf("%d",&ele);
            insert_at_begin(ele);
            break;
        case 2:
            printf("Enter the Element:  ");
            scanf("%d",&ele);
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
        default:
            printf("please enter the right number");
            break;
        }
    }
}
