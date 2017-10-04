#include <stdio.h>
#include <string.h>
typedef struct bnode
{
  int srno;
  char name[10];
  char auth[10];
  char branch[10];
  char sub[10];
  int tnoc;
  int lnoc;
  struct bnode *next;
  struct bnode *prev;
}BNODE;

typedef struct bdlist
{
  BNODE *head;
  BNODE *tail;
  int nbooks;
 }BDLIST;

int addbook(BDLIST *l,char name[10],char auth[10],char branch[10],char sub[10],int tnoc)
{
  BNODE *newbook=(BNODE *)malloc(sizeof(BNODE));
  if(newbook==NULL)
  {
    return 0;
  }
  else
  {
    strcpy(newbook->name,name);
    strcpy(newbook->auth,auth);
    strcpy(newbook->branch,branch);
    strcpy(newbook->sub,sub);
    newbook->tnoc=tnoc;
    newbook->lnoc=0;
    if(l->tail!=NULL)
    {
      BNODE *temp=l->tail;
      int sr=temp->data;
      newbook->srno=sr+1;
      temp->next=newbook;
      newbook->prev=temp;
      newbook->next=NULL;
      l->tail=temp;
    }
    else
    {
      l->head=newbook;
      l->tail=newbook;
      newbook->srno=1;
      newbook->next=NULL;
      newbook->prev=NULL;
    }
      
    l->nbooks++; 
    return 1;
  }
}
int deletebook(BDLIST *l,char name[10])
{
  if(l->head==NULL)
  {
    return 0;
  }
  BNODE *temp=l->head;
  while(strcmp(l->name,name)!=0 && temp!=NULL)
  {
    temp=temp->next;
  }
  if(temp==NULL)
  {
    return 0;
  }
  
  else
  {
    if(l->head!=temp)
    {
      
      BNODE *temp1=temp->prev;
      temp1->next=temp->next;
      if(temp->next==NULL)
      {
        free(temp);
        l->tail=temp1;
      }    
      else
      {
        temp->next->prev=temp1;
        free(temp);
      }
    }
    else
    {
      if(l->nbooks==1)
      {
        free(l->head);
        l->head==NULL;
        l->tail==NULL;
      }
      else
      {
        l->head->next->prev=NULL;
        BNODE *temp2=l->head;
        l->head=l->head->next;
        free(temp2);
      }
      l->nbooks--;
      return 1;
    }
        
    
  
  
