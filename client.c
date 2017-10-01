#include <stdio.h>
typedef struct node
{
  int srno;
  char nob[10];
  char auth[10];
  char branch[10];
  char sub[10];
  int tnoc;
  int lnoc;
  struct node *next;
  struct node *prev;
}NODE;
//srno- serial number
//nob-name of the book
//auth-author
//sub-subject
//tnoc-total number of copies
//lnoc=lent number of copies

typedef struct dlist
{
  NODE *head;
  NODE *tail;
  int nbooks;
 }DLIST;
