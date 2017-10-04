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

typedef struct tbnode
{
  char name[4];
  struct tnode *p1;
  struct tnode *p2;
  struct tnode *p3;
  struct tnode *p4;
}TBNODE;

typedef struct tsubnode
{
  char name[6];
  BNODE *head;
}SUBNODE;

typedef struct tree
{
  TNODE *head;
}TREE;
  
int addbook(BDLIST *l,char name[10],char auth[10],char branch[10],char sub[10],int tnoc);
int deletebook(BDLIST *l,char name[10]);

