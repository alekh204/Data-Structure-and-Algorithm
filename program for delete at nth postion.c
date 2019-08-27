
#include<stdio.h>
#include<stdlib.h>

struct Node
{
 int data;
 struct Node* next;
};

struct Node* head;

void insertNode(int data)
{
 
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
    temp1->data = data;
    if(head==NULL)
    {
        head = temp1;
        temp1->next=NULL;
    }
    struct Node* temp2=head;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }    
    temp2->next= temp1;
    temp1->next = NULL;

}

void deleteNode(int position)
{
    struct Node* temp1 = head;    
    int i;
    if(position==1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    for(i=0;i<position-2;i++)
    {
        temp1=  temp1->next;
    }
    struct Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    
}

void printData()
{
  struct Node* temp = head;
  while(temp!=NULL)
  {
   printf("%d\n", temp->data);
   temp= temp->next;
  }
  printf("\n");
} 

int main(void)
{
    int pos;
 head = NULL;
 
 insertNode(9);
 insertNode(5);
 insertNode(7);

    scanf("%d",&pos);
    deleteNode(pos);

 printData();
 return 0;
}