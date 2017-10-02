#include <stdio.h>
#include <string.h>
typedef struct node
{
  int srno;
  char name[10];
  char auth[10];
  char branch[10];
  char sub[10];
  int tnoc;
  int lnoc;
  struct node *next;
  struct node *prev;
}NODE;

typedef struct dlist
{
  NODE *head;
  NODE *tail;
  int nbooks;
 }DLIST;

int addbook(DLIST *l,char name[10],char auth[10],char branch[10],char sub[10],int tnoc)
{
  NODE *newbook=(NODE *)malloc(sizeof(NODE));
  strcpy(newbook->name,name);
  strcpy(newbook->auth,auth);
  strcpy(newbook->branch,branch);
  strcpy(newbook->sub,sub);
  newbook->tnoc=tnoc;
  newbook->lnoc=0;
  NODE *temp=l->tail;
  temp->next=newbook;
  newbook->prev=temp;
}
  
    
