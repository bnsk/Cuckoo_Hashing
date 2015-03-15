/*This is an implementation of Cuckoo hashing for storing integers.Here we are fixing the size of the table as 16,i.e. the table at any point of time can hold only a maximum of 16 elements.Do not insert repitions...*/

#include<stdio.h>
#include<math.h>

#define NUM 16  //maximum number of elements of in the table
#define MAX 24  //maximum number of times we try to insert is 6logn where n is 16 hence MAX=6 * log(16)=24

void Insert_First(int ,int *);
void Insert(int,int *);
void Delete(int ,int *);
int One_Hash(int );       //normal modulo hash function(division hash function) given by Cormen
int Two_Hash(int );       //knuth variant of the division hash function
void Search(int,int * );
static int count=0;   

int main(int argc,char *argv[])
{
  int i,choice,element;
  int table[NUM];  //table for holding the elements

  for(i=0;i<NUM;i++)     //Initialize the entire table to -1 which tells us that it is empty
    table[i]=-1;       
  
  printf("\nWhat do you want to do?Please enter the correct number from the following options in the menu...\n");
  printf("MENU:\n");
  printf("1-Insert.\n");
  printf("2-Delete.\n");
  printf("3-Print.\n");
  printf("4-Search.\n");
  printf("5-Exit.\n");
  printf("\nEnter your choice now:\n");
  scanf(" %d",&choice);

  while(choice!=5)
  {
   switch(choice)
   {
  
     case 1: printf("\nPlease enter the integer you want to insert: \n");
             scanf(" %d",&element);
             Insert(element,table);
             break;

     case 2: printf("\nEnter the element you want to delete: \n");
             scanf(" %d",&element);
             Delete(element,table);
             break;

     case 3: printf("\nThe elements in the table are: \n");
             for(i=0;i<NUM;i++)
              printf(" %d\t",table[i]);
             break;

     case 4: printf("\nEnter the element you want to search: \n");
             scanf(" %d",&element);
             Search(element,table);
             break;     

     default: printf("\nSorry!You entered the wrong choice...Try again...\n");  
              break;
    }  //end of switch               

      printf("\nWhat do you want to do?Please enter the correct number from the following options in the menu...\n");
      printf("MENU:\n");
       printf("1-Insert.\n");
      printf("2-Delete.\n");
      printf("3-Print.\n");
      printf("4-Search.\n");
      printf("5-Exit.\n");
  
      printf("\nEnter your choice now:\n");
      scanf(" %d",&choice);
  }  //end of while     
} //end of main


int One_Hash(int x)
{ 
  return (x % NUM);
}

int Two_Hash(int x)
{
  int y=(x*(x+3))%NUM;
  return y;
  
}  

void Delete(int x,int table[])
{
 int y=One_Hash(x);
 int z=Two_Hash(x);
 if(table[y]==x)
  table[y]=-1;
 else if(table[z]==x)
   table[z]=-1;
      else
       printf("\nSorry element was not found in the list...\n");
}

void Search(int x,int table[])
{
int y=One_Hash(x);
 int z=Two_Hash(x);
 if(table[y]==x)
  printf("\nThe element is found in position %d.",y);
 else if(table[z]==x)
   printf("\nThe element is found in position %d.",z);
      else
       printf("\nSorry element was not found in the list...\n");


}
void Insert(int x,int table[])
{
  while(count<24)    //6log4=24
   { 
  int y=One_Hash(x);
 count+=1;
  if(table[y]==-1)
  {
    table[y]=x;  
     return;
  }
  else
  {
    int temp=table[y];
     table[y]=x;
    if(One_Hash(temp)==y)
    {
      int y=Two_Hash(temp);
       x=table[y];
        table[y]=temp;
           }
     else
     {
       int y=One_Hash(temp);
         x=table[y];
        table[y]=temp;
      
   
     } 
    } 
    
  }

count=0;
}



