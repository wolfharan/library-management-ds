#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct library library;
typedef struct booknode booknode;
typedef struct studentlist studentlist;
typedef struct studentnode studentnode;
typedef struct subnode subnode;
//Library Structure containing the subject nodes,total number of books and a list of students who have borrowed books from a library
struct library{
int nob;
subnode *CS;
subnode *EC;
subnode *MECH;
subnode *CIVIL;
studentlist *stus; //list of students who borrowed books from library.
} ;

struct booknode{
int srno;//serial no.
char name[30];
char auth[30];
int tnc ;//total number of copies that belong to the library.
int bnc;//no of copies borrowed by students from the library.
studentnode *bs[5];// student list of the students who have borrowed this book.
booknode *next;
};

struct studentlist{
studentnode *head;
studentnode *tail;
int nos; //number of students
};

struct studentnode{
  char name[30];
  int USN;
  booknode *blist[5]; //list books that a particular student has borrowed.
  int nob;
  studentnode *next;
  studentnode *prev;
};

//subnode is a node for suject.
struct subnode{
  booknode *head;
  booknode *tail;
  int nob;
};

init_lib(library *lib){
  //lib=(library *)malloc(sizeof(library));
  lib->CS=(subnode *)malloc(sizeof(subnode));
  lib->CS->head=NULL;
  lib->CS->tail=NULL;
  lib->CS->nob=0;
  lib->EC=(subnode *)malloc(sizeof(subnode));
  lib->EC->head=NULL;
  lib->EC->tail=NULL;
  lib->EC->nob=0;
  lib->MECH=(subnode *)malloc(sizeof(subnode));
  lib->MECH->head=NULL;
  lib->MECH->tail=NULL;
  lib->MECH->nob=0;
  lib->CIVIL=(subnode *)malloc(sizeof(subnode));
  lib->CIVIL->head=NULL;
  lib->CIVIL->tail=NULL;
  lib->CIVIL->nob=0;
  lib->stus=(studentlist *)malloc(sizeof(studentlist));
  lib->stus->head=NULL;
  lib->stus->tail=NULL;
  lib->stus->nos=0;
}

insert_book(library *lib,char name[],char auth[],int tnc,char sub[])
{
  booknode* temp=(booknode *)malloc(sizeof(booknode));
  strcpy(temp->name,name);
  strcpy(temp->auth,auth);
  temp->tnc=tnc;
  temp->bnc=0;
  temp->bs[0]=NULL;
  temp->next=NULL;
  temp->bs[1]=NULL;
  temp->bs[2]=NULL;
  temp->bs[3]=NULL;
  temp->bs[4]=NULL;
//to get the subject
    if(strcmp(sub,"CS")==0)
    {
      if(lib->CS->nob==0)
      {
        lib->CS->head=temp;
        lib->CS->tail=temp;
        temp->srno=0;

      }
      else
      {
        lib->CS->tail->next=temp;
        temp->srno=lib->CS->nob;
        lib->CS->tail=temp;

      }
      lib->CS->nob++;
    }
    else if(strcmp(sub,"EC")==0)
    {
      if(lib->EC->nob==0)
      {
        lib->EC->head=temp;
        lib->EC->tail=temp;
        temp->srno=0;

      }
      else
      {
        lib->EC->tail->next=temp;
        temp->srno=lib->EC->nob;
        lib->EC->tail=temp;

      }
      lib->EC->nob++;
    }
    else if(strcmp(sub,"MECH")==0)
    {
      if(lib->MECH->nob==0)
      {
        lib->MECH->head=temp;
        lib->MECH->tail=temp;
        temp->srno=0;

      }
      else
      {
        lib->MECH->tail->next=temp;
        temp->srno=lib->MECH->nob;
        lib->MECH->tail=temp;

      }
      lib->MECH->nob++;
    }
    else if(strcmp(sub,"CIVIL")==0)
    {
      if(lib->CIVIL->nob==0)
      {
        lib->CIVIL->head=temp;
        lib->CIVIL->tail=temp;
        temp->srno=0;

      }
      else
      {
        lib->CIVIL->tail->next=temp;
        temp->srno=lib->CIVIL->nob;
        lib->CIVIL->tail=temp;

      }
      lib->CIVIL->nob++;
    }


    lib->nob++;

}
display_all_books(library *lib)
{

  booknode* temp=lib->CS->head;
  while(temp!=NULL)
  {
    printf("Serial no.: %d \n",temp->srno);
    printf("Name of the book: %s \n",temp->name);
    printf("Author of the book: %s \n",temp->auth);
    printf("Subject: CS \n");
    printf("Total number of copies: %d \n",temp->tnc);
    printf("Available number of copies: %d \n",(temp->tnc-temp->bnc));
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    temp=temp->next;
  }
  temp=lib->EC->head;
  while(temp!=NULL)
  {
    printf("Serial no.: %d \n",temp->srno);
    printf("Name of the book: %s \n",temp->name);
    printf("Author of the book: %s \n",temp->auth);
    printf("Subject: EC \n");
    printf("Total number of copies: %d \n",temp->tnc);
    printf("Available number of copies: %d \n",(temp->tnc-temp->bnc));
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    temp=temp->next;
  }
  temp=lib->MECH->head;
  while(temp!=NULL)
  {
    printf("Serial no.: %d \n",temp->srno);
    printf("Name of the book: %s \n",temp->name);
    printf("Author of the book: %s \n",temp->auth);
    printf("Subject: MECH \n");
    printf("Total number of copies: %d \n",temp->tnc);
    printf("Available number of copies: %d \n",(temp->tnc-temp->bnc));
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    temp=temp->next;
  }
  temp=lib->CIVIL->head;
  while(temp!=NULL)
  {
    printf("Serial no.: %d \n",temp->srno);
    printf("Name of the book: %s \n",temp->name);
    printf("Author of the book: %s \n",temp->auth);
    printf("Subject: CIVIL \n");
    printf("Total number of copies: %d \n",temp->tnc);
    printf("Available number of copies: %d \n",(temp->tnc-temp->bnc));
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    temp=temp->next;
  }
}
booknode* find_book(library *lib,char sub[],char name[])
{
  booknode *temp;
  if(strcmp(sub,"CS")==0)
  {
    temp=lib->CS->head;
  }
  else if(strcmp(sub,"EC")==0)
  {
    temp=lib->EC->head;
  }
  else if(strcmp(sub,"MECH")==0)
  {
    temp=lib->MECH->head;
  }
  else if(strcmp(sub,"CIVIL")==0)
  {
    temp=lib->CIVIL->head;
  }
  while((temp!=NULL)&&(strcmp(name,temp->name)!=0))
  {
    temp=temp->next;
  }
  return temp;
}
studentnode *find_student(library *lib,char name[])
{
  studentnode *temp=lib->stus->head;
  while((temp!=NULL)&&(strcmp(name,temp->name)!=0))
  {
    temp=temp->next;
  }
  return temp;}

int lend_book(library *lib,char sub[],char name[],int USN,char stu[])
{
  booknode *tempb=find_book(lib,sub,name);
  if(tempb==NULL || tempb->bnc==5)
  {
    printf("The Book is not Available\n");
  }
  if(lib->stus->head==NULL)
  {


    studentnode *temp=(studentnode *)malloc(sizeof(studentnode));
    temp->USN=USN;
    strcpy(temp->name,stu);
    temp->nob=0;
    temp->next=NULL;
    temp->prev=NULL;
    tempb->bs[0]=temp;
    temp->blist[0]=NULL;

    temp->blist[1]=NULL;
    temp->blist[2]=NULL;
    temp->blist[3]=NULL;
    temp->blist[4]=NULL;


      tempb->bnc++;
      temp->blist[0]=tempb;
      temp->nob++;

    lib->stus->head=temp;
    lib->stus->tail=temp;
    lib->stus->nos++;
    return 1;
  }
  else
  {
    studentnode *temp=find_student(lib,stu);
    if(temp==NULL)
    {
      studentnode *temp1=(studentnode *)malloc(sizeof(studentnode));
      temp1->USN=USN;
      strcpy(temp1->name,stu);
      temp1->nob=0;
      temp1->next=NULL;
      tempb->bs[tempb->bnc]=temp1;


        tempb->bnc++;
        temp1->blist[0]=tempb;
        temp1->nob++;

      temp1->prev=lib->stus->tail;
      lib->stus->tail->next=temp1;
      lib->stus->tail=temp1;
      lib->stus->nos++;
      return 1;
    }
    else{

        if(temp->nob==5)
        {
          printf("The Student has reached the maximum limit of books\n");
        }
        tempb->bs[tempb->bnc]=temp;
        tempb->bnc++;
        temp->blist[temp->nob]=tempb;
        temp->nob++;
        return 1;

    }
  }
}
return_book(library *lib,char bname[],char sub[],char stuname[])
{
  booknode* tempb=find_book(lib,sub,bname);
  studentnode* temps=find_student(lib,stuname);
  if(tempb==NULL || temps==NULL)
  {
    printf("Book Not avaible\n");
  }
  else
  {

    int p=0;
    while(p<tempb->bnc && tempb->bs[p]!=temps )
    {
      p++;
    }
    if(tempb->bs[p]!=temps)
    {
      printf("Book Not avaible\n");
    }
    else
    {

      while(p<4)
      {
        tempb->bs[p]=tempb->bs[p+1];
        p++;
      }
      tempb->bnc--;
    }
    int q=0;
    while(q<temps->nob && temps->blist[q]!=tempb )
    {
      q++;
    }
    if(temps->blist[q]!=tempb)
    {
      printf("Book Not avaible\n");
    }
    else
    {

      while(q<4)
      {
        temps->blist[q]=temps->blist[q+1];
        q++;
      }
      temps->nob--;
    }
  }
  return 1;

}

//Given a student, the output being the list of books he has borrowed.
display_books_borrowed_by(library *lib,char name[])
{
  studentnode* temps=find_student(lib,name);
  if(temps==NULL ||temps->nob==0)
  {
    printf("Student Didn't Borrow Any Books");
  }
  else{
    int l=0;
    printf("The Books borrowed By %s are as follows: \n",temps->name);

    while(l<temps->nob)
    {

      printf("Name of the book:%s \n",temps->blist[l]->name);
    //  printf("USN : %d \n",temps->USN);
    //  printf("No. if books borrowed by the student:%d \n",temps->nob);
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      l++;
    }
  //  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  }
}


//Given a book, Output being the list of students who borrowed the book.
display_books_lent_to(library *lib,char name[],char sub[])
{
  booknode *tempb=find_book(lib,sub,name);
  if(tempb==NULL ||tempb->bnc==0)
  {
    printf("No Student Borrowed This Book \n");
  }
  else{
  int l=0;
  printf("The List Of Students Who Borrowed this Books is As Follows: \n");

  while(l<tempb->bnc)
  {

    printf("%s \n",tempb->bs[l]->name);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    l++;
  }
//printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
}
void main()
{
  library lib;
  init_lib(&lib);

char bname[30];
char bauth[20];
char branch[5];
char sname[20];
int USN;
int ch;
int fl=0;

printf("Welcome to the Library Management System \n");
printf("Notes:\n The Available Branches or Subjects are- CS,EC,MECH,CIVIL\n Each Student can Borrow Maximum of 5 books \n Each book has 5 total copies\n");
printf("---------------------------------------------------------------\n");
while(fl!=-1){
printf("Here is a list of operations you can perform: \n");
printf("1.Insert Book \n");
printf("2.Lend Book\n");
printf("3.Accept Back the Book \n");
printf("4.Display All Books in the library \n");
printf("5.Display Books Borrowed By a particular student \n");
printf("6.Display List Of Students who borrowed a particular Book \n");
printf("---------------------------------------------------------------\n");

printf("Enter your Choice:   ");

scanf("%d",&ch);
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
switch(ch)
{
  case 1:printf("Enter the name of the book you want to insert\n");
          scanf("%s",bname);
          //fgets(bname,100,stdin);
          printf("Enter the name of the author \n");
          scanf("%s",bauth);
          //fgets(bauth,100,stdin);
          printf("Enter the branch the book belongs to\n");
          scanf("%s",branch);
          //fgets(branch,100,stdin);
          insert_book(&lib,bname,bauth,5,branch);

          break;
  case 2:printf("Enter the name of the book you want to lend\n");
        scanf("%s",bname);

        //gets(bname);
        printf("Enter the branch the book belongs to\n");
        scanf("%s",branch);
        //gets(branch);
        printf("Enter the students name\n");
        scanf("%s",sname);
        //gets(sname);
        printf("Enter USN\n");
        scanf("%d",&USN);
        lend_book(&lib,branch,bname,USN,sname);

        break;
case 3:printf("Enter the name of the book you want to accept back\n");
      scanf("%s",bname);
      //gets(bname);
      printf("Enter the branch the book belongs to\n");
      scanf("%s",branch);
      //gets(branch);
      printf("Enter the students name\n");
      scanf("%s",sname);
      //gets(sname);
      return_book(&lib,bname,branch,sname);
      break;
case 4:display_all_books(&lib);
        break;
case 5:printf("Enter the name of the student to list his borrowed books\n");
        scanf("%s",sname);
        //gets(sname);
        display_books_borrowed_by(&lib,sname);
        break;
case 6:printf("Enter the name of the book\n");
        scanf("%s",bname);
        //gets(bname);
        printf("Enter the subject of the book\n");
        scanf("%s",branch);
        //gets(branch);
        display_books_lent_to(&lib,bname,branch);
        break;
default: printf("invalid option");
        fl=-1;


}
}

}
