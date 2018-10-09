#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    long long num,m;
    int count=0,flag=0;
    int r,r2,rev=0,rev2=0,n,sum=0,sum2=0;
    
    
    printf("\nCard Number: ");
    num=get_long_long();
    
    while(num<=0 || flag!=1)
    {
        m=num;
        count=0;
        while(m>0)
        {
            ++count;
            m=m/10;
        }
     //  printf("\nCount=%d",count);
        if(count ==13 || count==15 || count==16)
        {
            flag=1;
        }
        else
        {
            printf("\nRetry: ");
            num=get_long_long();
        }
    }
    //printf("\nCount=%d",count);
    m=num;
    
    while(m>0)
    {
        r=m%10;
        rev=rev*10+r;
        m/=10;
        r2=m%10;
        rev2=rev2*10+r2;
        m/=10;
    }
   // printf("\nRev=%d,Rev2=%d",rev,rev2);
    
    if(count==13 || count==15)
    {
        while(rev2>0)
        {
            r=rev2%10;
            r*=2;
            if(r>9)
            {
                r2=r%10;
                r/=10;
                sum+=r+r2;
            }
            else
            sum+=r;
            
            rev2/=10;
        }
        
        while(rev>0)
        {
            r=rev%10;
            sum2+=r;
            rev/=10;
        }
        sum2+=sum;
    }
    
    else
    {
        while(rev>0)
        {
            r=rev%10;
            r*=2;
            if(r>9)
            {
                r2=r%10;
                r/=10;
                sum+=r+r2;
            }
            else
            sum+=r;
            
            rev/=10;
        }
        
        while(rev2>0)
        {
            r=rev2%10;
            sum2+=r;
            rev2/=10;
        }
        sum2+=sum;
    }
   // printf("\nsum2=%d",sum2);
    if(sum2%10==0)
    {
        m=num;
        m=m/pow(10,count-2);
        n=m/10;
    
        if(m==34 || m==37) 
        printf("AMEX\n");
        if (m>=51 && m<=55) 
        printf("MASTERCARD\n");
        if(n==4)
        printf("VISA\n");
    
    }    
    else
    printf("INVALID\n");
    return 0;
}	
