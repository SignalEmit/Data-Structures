#include<stdio.h>
#include<stdlib.h> 
typedef int elemtype;
typedef struct Node
{elemtype data;
struct Node* next; 
}Node,*linklist;
 linklist *head;
construct()
{*head=(linklist)malloc(sizeof(Node));
(*head)->next=NULL;
 } 
 void creathead(linklist head)
 {Node *s;
 char c;
 int flag=1;
 while(flag)
	{c=getchar();
	if(c!='$')
		{
			s=(Node *)malloc(sizeof(Node));
			s->data=c;
			s->next=head->next;
			head->next=s;
		}
		else flag=0;
		 }	 
 }
 void display(linklist *head) 
{
 linklist *p;
  p=head->next;
  while (p!=NULL)
    {
       printf("%d   ",p->data);
       p=p->next;
    }
}
 int main()
 {
 	construct();
	creathead(&head);
	display(&head); 
 }
 

