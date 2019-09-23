#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
  int data;
  struct node *link;
}node;
node *front=NULL,*rear=NULL;
void Equeue(int x);
void Dqueue();
void display();

void main()
{
  int ch,x;
  int choice;
  do
    {
      printf("\n1)push\n2)pop\n3)Display\n\nChoose your option:");
      scanf("%d",&ch);
      switch(ch)
	{
	case 1:printf("enter element:");
	  scanf("%d",&x);
	  Equeue(x);
	  break;
	case 2:Dqueue();
	  break;
	case 3:display();
	  break;
	default:printf("Error");
	}
      printf("\nDo you want to continue(1/0):");
      scanf("%d",&choice);
    }
  while(choice);
}

void Equeue(int x)
{
  node *newnode=(node*)malloc(sizeof(node));
  newnode->data=x;
  node* temp=front;
  int count=0;
  while(temp!=NULL){
    count++;
    temp=temp->link;
  }
  if(front==NULL){
    front=newnode;
    rear=newnode;
    rear->link=NULL;
    return;
  }
  else{
    rear->link=newnode;
    rear=newnode;
    rear->link=NULL;
    return;
  }
}

void Dqueue()
{
  node *temp;  
  if(front==NULL)
    printf("\nQUEUE UNDERFLOW!!!\n");
  else if(front!=rear)
    {
      temp=front;
      front=front->link;
      free(temp);
      return;
    }
  
}

void display()
{
  node*p;
  p=front;
  while(p!=NULL)
    {
      printf("%d\t",p->data);
      p=p->link;
    }
}
	     
