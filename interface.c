#include "server.h"
 void main()
 {
   TREE *T=(TREE *)malloc(sizeof(TREE));
   TNODE *PES=(TNODE *)malloc(sizeof(TNODE));
   TNODE *b1=(TNODE *)malloc(sizeof(TNODE));
   TNODE *b2=(TNODE *)malloc(sizeof(TNODE));
   TNODE *b3=(TNODE *)malloc(sizeof(TNODE));
   TNODE *b4=(TNODE *)malloc(sizeof(TNODE));
   strcpy(b1->name,"CSE");
   strcpy(b2->name,"ECE");
   strcpy(b3->name,"EEE");
   strcpy(b4->name,"MECH");
   PES->p1=b1;
   PES->p2=b2;
   PES->p3=b3;
   PES->p4=b4;
   
   
   
