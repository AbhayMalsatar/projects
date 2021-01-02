#include<stdio.h>
 int palindrom(int n)
       {
             int a,b=0;
       while(n>0)
    {
        a=n%10;
        b=b*10+a;
        n=n/10;
    }
    return b;
}
int armstrong(int n)
{
    int a,b=0;
    while(n>0)
    {
        a=n%10;
        b=b+(a*a*a);
        n=n/10;
    }
    return b;
}
int fact(int n)
{
    int a=1;
    for( int i=1;i<=n;i++)
    {
       a=a*i;
    }
    return a;
}
int krishnamurti(int n)
{
	int a,c,b=0;
	while(n>0)
	{
		a=n%10;
		c=fact(a);
		b=b+c;
		n=n/10;
	}
	return b;
}
int neonnumber(int n)
{
    int a,b,c=0;
    a=n*n;
    while(a>0)
    {
    	b=a%10;
    	c=c+b;
    	a=a/10;
	}
	return c;
}
int main()
{
    int e,b,c,d,l,u,a;
    int n;
    printf("*Welcome in my program\n*Here,I Know you which Number whose Palindrome number,Krishnamurty Number,Neon Number,armstrong number\n");
    printf("*************************************************************************************************\n");
    while(1)
    {
        printf("\n1.continue\n");
        printf("0.exit\n");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
	printf("Enter the length of number:\n");
	scanf("%d\n%d",&l,&u);
	while(l<0 || u<0)
    {
        printf("Negative number is not allowed\n");
        printf("please Renter limit:\n");
        scanf("%d\n%d",&l,&u);
    }
    printf("***********************************************************************\n");
	  for(int i=l;i<=u;i++)
      {
         b=neonnumber(i);
		if(b==i)
		{
		    printf("%d - neon number\n",b);
		}
        a=krishnamurti(i);
        if(e==i)
		{
           printf("%d - krishnamurty number\n",e);
		}
		c=armstrong(i);
		if(c==i)
        {
            printf("%d - armstrong number\n",c);
        }
        d=palindrom(i);
        if(d==i)
        {
            printf("%d - palindrom number\n",d);
        }
      }
      break;
      case 0:
            exit(0);
            break;
        default:
            printf("Wrong number");
            break;
}
     printf("*********************************************************************************\n");
        }
    }
