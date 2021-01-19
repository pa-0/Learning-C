#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  

void insertValue(int item)  
{  
  struct node *ptr,*temp;  
  ptr = (struct node*)malloc(sizeof(struct node));      
  if(ptr == NULL)  
  {  
    printf("NO MORE SPACE");     
  }  
  else  
  { 
    ptr->data = item;  
    if(head == NULL)  
    {  
      ptr -> next = NULL;  
      head = ptr;
    }  
    else  
    {  
      temp = head;  
      while (temp -> next != NULL)  
      {  
        temp = temp -> next;  
      }  
      temp->next = ptr;  
      ptr->next = NULL;  
      
    }  
  }  
}  


void main()
{
  float avg;
  char ch;
  int sum, c, temp;
  sum=0;
  c=0;
	while(c<8)
  {
    char ch;
    printf("Enter a test score: ");
    scanf("%d",&temp);
    sum=sum+temp;
    insertValue(temp);
    c++;
    
    printf("Would you like to continue? Y/N ");
    scanf(" %c",&ch);
    if (ch=='\0')
    {
      ch='Y';
    }
    ch=toupper(ch);
    if (ch == 'N')
      break;
  }  
  avg=sum/c;
  printf("%.2f is the Average Score\n",avg);
}
