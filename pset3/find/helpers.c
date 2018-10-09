/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include "helpers.h"


/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(value<0)
    return false;
    
    else
    {
        int beg=0,end=n-1,mid;
      do
      {
          
          mid = (beg+end)/2;
          if (value == values[mid]) 
            return true;
         else if(value < values[mid]) 
            end=mid-1;
          else
            beg=mid+1;
          
      }while(beg<=end);
      
    }
     
      return false;
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    
    int i, j,temp;
   for (i = 0; i < n-1; i++)      
     {
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (values[j] > values[j+1])
              {
                  temp=values[j];
                  values[j]=values[j+1];
                  values[j+1]=temp;
              }
     }          
    return;
}
