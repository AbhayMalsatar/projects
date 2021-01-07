#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float find_max(float a[],int arr_size)
{
    float max_element = a[0];
    for(int i = 1;i < arr_size; i++)
    {
        if(max_element < a[i])
        {
            max_element = a[i];
        }
    }
    return max_element;
}



float find_min(float a[],int arr_size)
{
    float min_element = a[0];
    for(int i = 1;i < arr_size; i++)
    {
        if(min_element > a[i])
        {
            min_element = a[i];
        }
    }
    return min_element;
}



float find_mid(float a[],int arr_size)
{
    float mid_element ;
      for(int i = 0;i < arr_size ; i++){
        if(arr_size % 2 == 0)
        {
            mid_element = (a[arr_size/2] + a[arr_size/2 - 1])/2;
        }
        else
        {
            mid_element = a[arr_size/2];
        }
      }
     return mid_element;
}

float find_avg(float a[],int arr_size)
{
    float  avg_element, sum =0;

    for(int i =0; i < arr_size; i++)
    {
        sum += a[i];
    }

    avg_element = sum / arr_size;

    return avg_element;
}

float find_var(float a[],int arr_size)
{
    float sum = 0, var;
    float avg = find_avg(a,arr_size);

    for(int i =0; i < arr_size; i++)
    {
        a[i] = a[i] - avg;
    }

    for(int i =0; i < arr_size; i++)
    {
        a[i] = a[i] * a[i];
    }

    for(int i =0; i < arr_size; i++)
    {
        sum += a[i];
    }
    var = sum / (arr_size - 1);

    return var;
}

float find_std_dev(float a[],int arr_size)
{
    float var = find_var( a ,  arr_size);
    float std_dev = sqrt(var);

    return std_dev;
}

float find_fre(float a[],int arr_size)
{
    int fr[arr_size];
    int visited = -1;

    for(int i = 0; i < arr_size; i++){
        int count = 1;
        for(int j = i+1; j < arr_size; j++){
            if(a[i] == a[j]){
                count++;
                fr[j] = visited;
            }
        }
        if(fr[i] != visited)
            fr[i] = count;
    }

    for(int i =0; i < arr_size; i++)
    {
        if(fr[i] >= 1){
        printf("%.1f  -  %d\n" ,a[i],fr[i]);
        }
    }
}


int random_ele()
{
    int n = rand()%(20 + 10 - 1);
    return n;
}


int main()
{
    int arr_size ,b ,c ;
    float max_ele ,min_ele ,mid_ele ,avg_ele ,var_of_ele ,std_of_ele;
    float a[arr_size+6];
    while(1)
    {
        printf("\n\n1.Build Array\n");
        printf("2.Display Array\n");
        printf("3.Find frequency Array\n");
        printf("0.exit\n");
        scanf("%d",&b);
        switch(b)
        {
        case 1:
            printf("Enter the size:  ");
            scanf("%d",&arr_size);
            printf("\n1.generate random Array\n");
            printf("2.Array create by user\n");
            scanf("%d",&c);
            if(c == 1){
                for(int i = 0;i < arr_size ; i++)
                {
                     a[i] = random_ele();
                }
                printf("Array Build successfully!!");
            }
            else{
                for(int i = 0;i < arr_size ; i++)
                {
                    scanf("%f",&a[i]);
                }
                printf("Array Build successfully!!");
            }
            break;
           case 2:
               if(arr_size == 0)
               {
                   printf("please build array!!");
               }
               else{
                   printf("******************************************************\n");
                   for(int i = 0;i < arr_size; i++){
                      printf("Index %d : %.1f\n",i,a[i]);
                   }
                   max_ele = find_max( a , arr_size);
                   printf("Maximum Element =  %.1f\n",max_ele);
                   min_ele = find_min( a ,  arr_size);
                   printf("Minimum Element = %.1f\n",min_ele);
                   mid_ele = find_mid( a ,  arr_size);
                   printf("Mid Element = %.2f\n",mid_ele);
                   avg_ele = find_avg( a ,  arr_size);
                   printf("Average of each Element = %.2f\n",avg_ele);
                   var_of_ele = find_var(a , arr_size);
                   printf("Variation of Array: %.2f\n",var_of_ele);
                   std_of_ele = find_std_dev( a , arr_size);
                   printf("Standard deviation of Array: %.2f\n",std_of_ele);
               printf("\n******************************************************\n");
                   }
               break;
           case 3:
               if(arr_size == 0)
               {
                   printf("please build array!!");
               }
               else{
                    printf("******************************************************\n");
                    find_fre(a , arr_size);
                    printf("******************************************************\n");
               }
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
