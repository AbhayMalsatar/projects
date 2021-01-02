#include<stdio.h>
int main()
{
    int a,d,f;
    float e,b,c;
    while(1)
    {
        printf("1.continue\n");
        printf("0.exit\n");
        scanf("%d",&a);
        printf("********************************************\n");
        switch(a)
        {
        case 1:
            printf("1.Enter the height in meter (0-2.72)\n");
            printf("2.Enter the height in centimeter(0-251)\n");
            printf("3.Enter the height in feet (0-9) and inch (0-12)\n");
            scanf("%d",&d);
            switch(d)
            {
               case 1:
              printf("Enter the height in meter: ");
            scanf("%f",&b);
            while(b>2.72)
            {
                printf("Height must be in limit\n");
                printf("renter height in meter: ");
                scanf("%f",&b);
            }
            printf("********************************************\n");
            printf("1.Enter the weight in pound\n");
            printf("2.Enter the weight in kilogram\n");
            scanf("%d",&f);
            switch(f)
            {
            case 1:
                printf("Enter the weight in pound: ");
                scanf("%f",&e);
                float feet=b*3.2808;
            float inch=b*39.3701;
            float n=((feet*12)+inch)*0.0254;
            float m=e/2.20462;
            float x=m/(n*n);
            printf("your BMI is %.2f\n",x);
            if(x<=18)
                printf("you are under weight");
            else if(x>18 && x<24)
                printf("you are normal");
            else if(x>24 && x<28)
                printf("you are over wieght");
            else
                printf("you are obesec");
                break;
            case 2:
                printf("Enter the weight in kilogram: ");
                scanf("%f",&e);
            feet=b*3.2808;
             inch=b*39.3701;
            n=((feet*12)+inch)*0.0254;
            x=e/(n*n);
            printf("your BMI is %.2f\n",x);
            if(x<=18)
                printf("you are under weight");
            else if(x>18 && x<24)
                printf("you are normal");
            else if(x>24 && x<28)
                printf("you are over wieght");
            else
                printf("you are obesec");
                break;
            default:
                printf("wrong number");
                break;
            }
            break;
            case 2:
                printf("Enter the height in centimeter: ");
            scanf("%f",&b);
            while(b>251)
            {
                printf("Please enter the height limit\n");
                printf("renter the height in centimeter: ");
                scanf("%f",&b);
            }
            printf("********************************************\n");
            printf("1.Enter the weight in pound\n");
            printf("2.Enter the weight in kilogram\n");
            scanf("%d",&f);
            switch(f)
            {
            case 1:
               printf("Enter the weight in pound: ");
            scanf("%f",&e);
            float meter=b*0.01;
            float z=meter*3.2808;
            float y=meter*39.3701;
            float l=((z*12)+y)*0.0254;
            float r=e/2.20462;
            float l1=r/(l*l);
            printf("your BMI is %.2f\n",l1);
            if(l1<=18)
                printf("you are under weight");
            else if(l1>18 && l1<24)
                printf("you are normal");
            else if(l1>24 && l1<28)
                printf("you are over weight");
            else
                printf("you are obesec");
                break;
            case 2:
                printf("Enter the weight in kilogram: ");
                scanf("%f",&e);
                meter=b*0.01;
             z=meter*3.2808;
             y=meter*39.3701;
            l=((z*12)+y)*0.0254;
            l1=e/(l*l);
            printf("your BMI is %.2f\n",l1);
            if(l1<=18)
                printf("you are under weight");
            else if(l1>18 && l1<24)
                printf("you are normal");
            else if(l1>24 && l1<28)
                printf("you are over weight");
            else
                printf("you are obesec");
                break;
            }
            break;
            case 3:
                printf("Enter the height in feet: ");
            scanf("%f",&b);
            while(b>9)
            {
                printf("Please enter height in limit\n");
                printf("renter height in feet: ");
                scanf("%f",&b);
            }
            printf("Enter the height in inch: ");
            scanf("%f",&c);
            while(c>12)
            {
                printf("please enter height in limit\n");
                printf("renter height in inch: ");
                scanf("%f",&c);
            }
            printf("********************************************\n");
            printf("1.Enter the weight in pound\n");
            printf("2.Enter the weight in kilogram\n");
            scanf("%d",&f);
            switch(f)
            {
            case 1:
            printf("Enter the weight in pound: ");
            scanf("%f",&e);
            float a1=((b*12)+c)*0.0254;
            float a2=e/2.20462;
            float x1=a2/(a1*a1);
            printf("your BMI is %.2f\n",x1);
            if(x1<=18)
                printf("you are under weight");
            else if(x1>18 && x1<24)
                printf("you are normal");
            else if(x1>24 && x1<28)
                printf("you are over wieght");
            else
                printf("you are obesec");
                break;
            case 2:
                printf("Enter the weight in kilogram: ");
                scanf("%f",&e);
             a1=((b*12)+c)*0.0254;
             x1=e/(a1*a1);
            printf("your BMI is %.2f\n",x1);
            if(x1<=18)
                printf("you are under weight");
            else if(x1>18 && x1<24)
                printf("you are normal");
            else if(x1>24 && x1<28)
                printf("you are over wieght");
            else
                printf("you are obesec");
                break;
                 default:
                printf("wrong number");
                break;
            }
            break;
            break;
          case 0:
             exit(0);
             break;
         default:
            printf("wrong number");
            break;
            }
            break;
            case 0:
             exit(0);
             break;
         default:
            printf("wrong number");
            break;
        }
        printf("\n********************************************\n\n");
    }
}
