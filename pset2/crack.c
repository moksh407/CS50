#define _XOPEN_SOURCE
#include <unistd.h>
#include<stdio.h>
#include <crypt.h>
#include<string.h>

//char *crypt(const char *key, const char *salt);
//50fkUxYHbnXGw
int main(int argc, char * argv[])
{
    if(argc!=2)
    {
        printf("\nUsage: ./crack hash\n");
        return 1;
    }
    
   
char key[100],salt[3],pass[5]={},*ans=NULL;
char fst[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";
int flag=1;

strcpy(key,argv[1]);
salt[0]=key[0];
salt[1]=key[1];
salt[2]='\0';

int l=0;

for(int i=0;i<2;i++)
{
  for(int k=0;k<65;k++)
  {
    for(int j=0;j<65;j++)
    {
        pass[i]=fst[j];
        if(i>0)
        { 
            l=i;
            while(l>0)
            {
                --l;
                pass[l]=fst[k];
            }
        } 
        else 
        ++k;
        
        ans=crypt(pass,salt);
        
       if(strcmp(ans,key)==0)
        {
            printf("\nPassword found!\nPassword=%s",pass);
             return 0;
        }
        else
        flag=0;
    }
  } 
}

printf("Checking for 3 chars long password...\n");
for(int i=2;i<3;i++)
{
    for(int k=0;k<65;k++)
    {
        for(int j=0;j<65;j++)
        {
            for(int h=0;h<65;h++)
            {
                pass[i]=fst[h];
                pass[i-1]=fst[j];
                pass[i-2]=fst[k];
                ans=crypt(pass,salt);
        
       if(strcmp(ans,key)==0)
        {
            printf("\nPassword found!\nPassword=%s",pass);
             return 0;
        }
        else
        flag=0;
                
            }
        }
    }
}

printf("Checking for 4 chars long password...\n");
for(int i=3;i<4;i++)
{
  for(l=0;l<65;l++)
  {
    for(int k=0;k<65;k++)
    {
        for(int j=0;j<65;j++)
        {
            for(int h=0;h<65;h++)
            {
                pass[i]=fst[h];
                pass[i-1]=fst[j];
                pass[i-2]=fst[k];
                pass[i-3]=fst[l];
                ans=crypt(pass,salt);
        
               if(strcmp(ans,key)==0)
                  {
                      printf("\nPassword found!\nPassword=%s\n",pass);
                    return 0;
                    }
                else
                flag=0;
                
            }
        }
    }
  }
}


if(flag==0)
 {
  printf("Password not found\n");
 return 2;
 }    
  
return 0;
}