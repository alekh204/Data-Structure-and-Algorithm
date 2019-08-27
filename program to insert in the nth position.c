

#include<stdio.h>
#include<stdlib.h>
void Insert(int, int);
void print();

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;

void main()
{
    head=NULL;
    Insert(3,1);
    Insert(2,2);
    Insert(4,2);
    print();
}

void Insert(int data, int n)
{
    struct Node* temp1=(struct Node*)malloc(sizeof(struct Node*));
    int i;
    temp1->data=data;
    temp1->next=NULL;
    if(n==1)//empty list
    {
        temp1->next=head;
        head=temp1;
        return;
    }
    struct Node* temp2=head;
    for(i=0;i<n-2;i++)//to traverse temp2 through the nodes
    {
        temp2=temp2->next;//to point temp2 to (n-1)th node after loop
    }
    temp1->next=temp2->next;// point new (nth)node to next node
    temp2->next=temp1;// to point the previous( n-1 th) node to new node
}

void print()
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    print("\n");
}