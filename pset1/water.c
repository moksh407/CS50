#include<stdio.h>
#include<cs50.h>

int main(void)
{
     printf("\nEnter minutes: ");
     int minutes=get_int();

     while(minutes<0)
     {
          printf("\nRetry: ");
      minutes=get_int();

          }
    printf("\nBottles:%d",12*minutes);
}