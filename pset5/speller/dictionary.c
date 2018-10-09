/**
 * Implements a dictionary's functionality.
 */

#include<stdbool.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include "dictionary.h"

//hashtable size
#define tsize 1000000
int dsize=0;
//nodes of linked list
typedef struct node
{
    char word[LENGTH+1];
    struct node *next;
}node;

//hashtable
node *hashtable[tsize]={NULL};

//hash function

int hash(const char * word)
{
    int hash=0,v=0;
    
    for(int i=0;word[i]!='\0';i++)
    {
        if(isalpha(word[i]))
          v=word[i]-'a'+1;
          
        else
        v=27;
        
        hash=(((hash<<3)+v)%tsize);
    }
    return hash;
}



/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    char temp[LENGTH+1];
    
    int a=strlen(word);
    for(int i=0;i<a;i++)
    {
        temp[i]=tolower(word[i]);
    }
    temp[a]='\0';
    
    int loc=hash(temp);
    
    if(hashtable[loc]==NULL)
    return false;
    
    node *ptr=hashtable[loc];
    
    while(ptr!=NULL)
    {
        if(strcmp(ptr->word,temp)==0)
        return true;
        ptr=ptr->next;
    }
    
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO
    FILE *ptr=fopen(dictionary,"r");
    
    if(ptr==NULL)
    return false;
    
    char word[LENGTH+1];
    
    while(fscanf(ptr,"%s\n",word)!=EOF)
    {
        ++dsize;
        
        node *newnode = malloc(sizeof(node));
        
        if(newnode==NULL)
        return false;
        
        strcpy(newnode->word,word);
        
        int loc=hash(word);
        
        if(hashtable[loc]==NULL)
        {
            hashtable[loc]=newnode;
            newnode->next=NULL;
        }
        
        else
        {
            newnode->next=hashtable[loc];
            hashtable[loc]=newnode;
        }
        
    }
    fclose(ptr);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    if(dsize>0)
    return dsize;
    
    else
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    int loc=0;
    
    while(loc<tsize)
    {
        if(hashtable[loc]==NULL)
        ++loc;
        
        else
        {
            while(hashtable[loc]!=NULL)
            {
                node *ptr=hashtable[loc];
                hashtable[loc]=ptr->next;
                free(ptr);
            }
            ++loc;
        }
    }
    return true;
}
