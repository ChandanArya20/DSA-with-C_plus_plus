#include "header.h"
int main()
{
    Node *head=nullptr;
    // Node *head= new Node(70);

    insertAtEnd(head,30);
    insertAtEnd(head,39);
    insertAtEnd(head,45);
    insertAtEnd(head,42);
    insertAtEnd(head,64);
    insertAtEnd(head,82);
    insertAtEnd(head,97);

    // Node *head1=nullptr;
    // insertAtEnd(head1,20);
    // insertAtEnd(head1,35);
    // insertAtEnd(head1,42);
    // insertAtEnd(head1,60);
    // insertAtEnd(head1,72);
    // insertAtEnd(head1,90);
   
    // insertAtBeg(head,20);
    // insertAtBeg(head,15);
    // insertAtBeg(head,10);



    // insertAtLoc(head,5,42);
    // insertBeforeNode(head,4,42);
    // insertAfterNode(head,3,42);

    // cout<<max(head)<<endl;
    // cout<<min(head)<<endl;

    // if(int pos=search(head,47))
    //     cout<<"Data found at position "<<pos<<endl;
    // else
    //     cout<<"Data not found"<<endl;

    // if(int pos=improvedSearch(head,47))
    //     cout<<"Data found at position "<<pos<<endl;
    // else
    //     cout<<"Data not found"<<endl;

    // cout<<isSorted(head)<<endl;

    // removeDuplicate(head);

    // cout<<delData(head,20)<<endl;
    // delData(head,12);

    // reverse(head); 

    // Node* third=merge(head,head1);
    // display(third);

    // cout<<midNode(head)<<endl;

    display(head);


    return 0;
}

void display(Node* p)
{
    while(p!=nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void Rdisplay(Node* p)
{
    while(p!=nullptr)
    {
        cout<<p->data<<" ";
        Rdisplay(p->next);
    }
}
void insertAtBeg(Node* &head,int data)
{
    Node *temp=new Node(data);
    temp->next=head;
    head=temp;
}
void insertAtEnd(Node* &head,int data)
{
    Node *temp=new Node(data);
    if(head==nullptr)
        head=temp;
    else
    {
        Node *p=head;
        while(p->next!=nullptr)
            p=p->next;
        p->next=temp;
    }
}
int length(Node *p)
{
    int count=0;
    while(p!=nullptr)
    {
        count++;
        p=p->next;
    }
    return count;
}
int Rlength(Node *p)
{
    if(p!=nullptr)
        return Rlength(p->next)+1;
    else
        return 0;
}
int sum(Node *p)
{
    int sum=0;
    while(p!=nullptr)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int Rsum(Node *p)
{
    if(p==NULL)
        return 0;
    else
        return Rsum(p->next)+p->data; 
}
int max(Node *p)
{
    int max=p->data;
    p=p->next;
    while(p!=NULL)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;
}
int min(Node *p)
{
    int min=p->data;
    p=p->next;
    while(p!=NULL)
    {
        if(p->data<min)
            min=p->data;
        p=p->next;
    }
    return min;
}
void insertAtLoc(Node* &head,int pos,int data)
{
    Node *temp, *p;
    if(pos<1 || pos>length(head)+1)
        return;
    temp=new Node(data);
    if(pos==1)
    {
        if(head=nullptr)
            head=temp;
        else
        {
            temp->next=head;
            head=temp;
        }
    }
    else
    {
        p=head;
        for(int i=1; i<pos-1; i++)
            p=p->next;
        temp->next=p->next;
        p->next=temp;
    } 
}
void insertBeforeNode(Node* &head,int pos,int data)
{
    Node *temp, *p;
    if(pos<1 || pos>length(head)+1)
        return;
    temp=new Node(data);
    if(pos==1)
    {
        if(head=nullptr)
            head=temp;
        else
        {
            temp->next=head;
            head=temp;
        }
    }
    else
    {
        p=head;
        for(int i=1; i<pos-2; i++)
            p=p->next;
        temp->next=p->next;
        p->next=temp;
    } 
}
void insertAfterNode(Node* &head,int pos,int data)
{
    Node *temp, *p;
    if(pos<1 || pos>length(head)+1)
        return;
    temp=new Node(data);
    if(pos==1)
    {
        if(head=nullptr)
            head=temp;
        else
        {
            temp->next=head;
            head=temp;
        }
    }
    else
    {
        p=head;
        for(int i=1; i<pos; i++)
            p=p->next;
        temp->next=p->next;
        p->next=temp;
    } 
}
void insertAtSorted(Node* &head,int data)
{
    Node *temp, *p, *q=NULL;
    temp=new Node(data);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        p=head;
        while(p!=NULL && data > p->data)
        {
            q=p;
            p=p->next;
        }
        if(p==head)                    //Mean you have to insert before head 
        {
            temp->next=head;
            head=temp;
        }
        else
        {
            temp->next=p;
            q->next=temp;
        }
    }
}
int search(Node *p, int key)
{
    int pos=1;
    while(p!=NULL)
    {
        if(p->data==key)
            return pos;
        p=p->next;
        pos++;       
    }
    return 0;
}
int improvedSearch(Node* &head, int key)
{
    int pos=0;
    Node *p=head, *q=nullptr;
    while(p!=NULL)
    {
        pos++;      
        if(p->data==key)
        {
            q->next=p->next;
            p->next=head;
            head=p;
        }
        q=p;
        p=p->next;
    }
    return pos;
}
bool isSorted(Node *p)
{
    int x=INT_MIN;
    while(p!=nullptr)
    {
        if(p->data<x)
            return false;
        x=p->data;
        p=p->next;
    }
    return true;  
}
int delData(Node* &head,int data)
{
    int pos=search(head,data);                         //for storing deleted data
    Node* temp;
    if(pos<1 || pos > length(head))
        return 0;
    if(pos==1)
    {
        if(head->next==nullptr)
        {
            temp=head;
            head=nullptr;
            delete temp;
        }
        else
        {
            temp=head;
            head=head->next;
            delete temp;
        }
    }
    else
    {
        Node* p=head;
        for(int i=1;i<pos-1;i++)
            p=p->next;
        temp=p->next;
        p->next=temp->next;
        delete temp;
    }
    return pos;
}
void removeDuplicate(Node *p)
{
    Node *nextPtr=p->next;
    while(nextPtr!=nullptr)
    {
        if(nextPtr->data==p->data)
        {
            p->next=nextPtr->next;
            delete nextPtr;
            nextPtr=p->next;
        }
        else
        {
            p=nextPtr;
            nextPtr=nextPtr->next;
        }
    }
}
void reverse(Node* &head)
{
    Node *p=head;
    Node *q=nullptr;
    Node *r=nullptr;
    while(p!=nullptr)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
}
Node *concate(Node *first, Node *sec)
{
    Node *p;
    if(first==NULL)
        first=sec;
    p=first;
    while(p->next!=NULL)
        p=p->next;
    p->next=sec;
    return first;
}
Node *merge(Node* first,Node *sec)
{
    Node *third, *last;
    if(first->data<sec->data)
    {
        third=last=first;
        first=first->next;
        last->next=nullptr;
    }
    else
    {
        third=last=sec;
        sec=sec->next;
        last->next=nullptr;
    }
    while(first!=nullptr && sec!=nullptr)
    {
        if(first->data<sec->data)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=nullptr;
        }
        else
        {
            last->next=sec;
            last=sec;
            sec=sec->next;
            last->next=nullptr;
        }
    }
    if(first!=nullptr){last->next=first;}
    if(sec!=nullptr){last->next=sec;}
    return third;
}
bool detectCycle(Node *p)
{
    Node *slow, *fast;
    slow=fast=p;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}
int midNode(Node *start)
{
    Node *fast,*slow;
    fast=slow=start;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
        
    }
    return slow->data;
}
void findIntersection(Node *first, Node *sec)
{
    Node *temp;
    stack<Node *> stk1,stk2;
    while(first!=nullptr){stk1.push(first);}
    while(sec!=nullptr){stk2.push(sec);}
    while(stk1.top()==stk2.top())
    {
        temp=stk1.top();
        stk1.pop();
        stk2.pop(); 
    }
    cout<<"Value at intersection node "<<temp->data<<endl;    
}
