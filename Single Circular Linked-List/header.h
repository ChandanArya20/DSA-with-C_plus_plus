#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int data;
    struct node *next;

}*head=NULL;

void create(int A[],int n);
void display(struct node *p);
int length(struct node *p);
void insertAtLoc(struct node *start,int pos,int data);
void delete(struct node *h, int pos);


void create(int A[],int n)
{
    int i;
    struct node *t,*last;
    head=(struct node *)malloc(sizeof(struct node)); 
    head->data=A[0];
    head->next=head;
    last=head;
    
    for(i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void display(struct node *h)
{
    do
    {
        printf("%d ",h->data);
        h=h->next;
    }while(h!=head);
    
}
int length(struct node *h)
{
    int count=0;
    do
    {
        count++;
        h=h->next;
    }while(h!=head);
    return count;
}
void inserAtBig(struct node *start,int data)
{
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    if(start==NULL)
        head=temp;
    else
    {
        temp->next=start;
        p=start;
        while(p->next!=start)
            p=p->next;
        p->next=temp;
        head=temp;
    }
}
void insertAtLoc(struct node *start,int pos,int data)
{
    struct node *temp,*p;
    if(pos<1 || pos>length(start)+1)
        return;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    if(pos==1)
    {
        if(head==NULL)
            head=temp;
        else
        {
            temp->next=start;
            p=start;
            while(p->next!=start)
                p=p->next;
            p->next=temp;
            head=temp; 
        }
    }
    else
    {
        p=start;
        for(int i=1; i<pos-1; i++)
            p=p->next;
        temp->next=p->next;
        p->next=temp;
    } 
}
void delete(struct node *start, int pos)
{
    struct node *p,*q=NULL;
    int i;
    if(pos<1 || pos>length(start))
        return;
    if(pos==1)
    {
        if(start->next==start)
        {
            free(start);
            head=NULL;
        }
        else
        {
            p=start;
            while(p->next!=start) 
                p=p->next;
            p->next=start->next;
            free(start);
            head=p->next;
        }
    }
    else
    {
        p=start;
        for(i=1;i<pos-1;i++)
            p=p->next;
        q=p->next;
        p->next=q->next;
        free(q);
    }
}