#include "server.h"
 void main()
 {
   TREE *T=(TREE *)malloc(sizeof(TREE));
   TBNODE *PES=(TBNODE *)malloc(sizeof(TNODE));
   TBNODE *b1=(TBNODE *)malloc(sizeof(TNODE));
   TBNODE *b2=(TBNODE *)malloc(sizeof(TNODE));
   TBNODE *b3=(TBNODE *)malloc(sizeof(TNODE));
   TBNODE *b4=(TBNODE *)malloc(sizeof(TNODE));
   strcpy(b1->name,"CSE");
   strcpy(b2->name,"ECE");
   strcpy(b3->name,"EEE");
   strcpy(b4->name,"MECH");
   PES->p1=b1;
   PES->p2=b2;
   PES->p3=b3;
   PES->p4=b4;
  SUBNODE *cs1=(SUBNODE *)malloc(sizeof(SUBNODE));
  SUBNODE *cs2=(SUBNODE *)malloc(sizeof(SUBNODE));
  SUBNODE *ec1=(SUBNODE *)malloc(sizeof(SUBNODE));
  SUBNODE *ee1=(SUBNODE *)malloc(sizeof(SUBNODE));
  SUBNODE *me1=(SUBNODE *)malloc(sizeof(SUBNODE));
  b1->p1=cs1;
  b1->p3=NULL;
  b1->p4=NULL;
  b1->p2=cs2;
  b2->p1=ec1;
  b2->p2=NULL;
  b2->p3=NULL;
  b2->p4=NULL;
  b3->p1=ee1;
  b3->p2=NULL;
  b3->p3=NULL;
  b3->p4=NULL;
  
  b4->p1=me1;
   
   
   
