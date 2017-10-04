#include "server.h"

TREE T;
TNODE b1;
TNODE b2;
TNODE b3;
TNODE b4;
strcpy(b1.name,"CSE");
strcpy(b2.name,"ECE");
strcpy(b3.name,"EEE");
strcpy(b4.name,"MECH");
TNODE PES;
T.head=&PES;
PES.p1=&b1;
PES.p2=&b2;
PES.p3=&b3;
PES.p4=&b4;


