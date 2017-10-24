#include <stdio.h>
#include <string.h>

typedef struct book{
  char name[10];
  char author[10];
  int srno;
  int noc[5];
  struct book* next;
  struct book* prev;
}book;

typedef struct subject{
  char name[10];
  book* start;
  book* end;
  int nob;
}subject;

int create_sub(subject* sub,char name[10])
{
  sub=(subject*)malloc(sizeof(subject));
  if(sub==NULL)
  {
    return 0;
  }
  strcpy(name,sub->name);
  sub->start=NULL;
  sub->end=NULL;
  nob=0;
  return 1;
}

int addbook(char name[10],char author[10],int srno,subject *sub)
{
  book* temp=(book*)malloc(sizeof(book));
  if(temp==NULL)
  {
    return 0;
  }
  
  strcpy(name,temp->name);
  strcpy(author,temp->author);
  temp->srno=srno;
  temp->next=NULL;
  temp->prev=NULL;
  if(sub->start==NULL)
  {
    sub->start=temp;
    sub->end=temp;
    nob++;
    return 1;
  }
  else
  {
    sub->end->next=temp;
    temp->prev=sub->end;
    sub->end=temp;
    nob++;
    return 1;
  }
}
