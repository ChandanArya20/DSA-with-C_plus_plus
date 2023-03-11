#include <iostream>
#include <climits>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data=0)
    {
        this->data=data;
        next=nullptr;
    }
};
void display(Node *p);
void Rdisplay(Node *p);
int length(Node *p);
int Rlength(Node *p);
int sum(Node *p);
int Rsum(Node *p);
int max(Node *p);
int min(Node *p);
int search(Node *p, int key);
void insertAtBeg(int data);
void insertAtEnd(Node* &head,int data);
void insertAtLoc(Node*start,int pos,int data);
void insertAtSorted(Node *start,int data);
void delData(Node *start,int pos); 
void removeDuplicate(Node *start);
void reverse(Node *start);
Node *concate(Node *first, Node *second);
Node *merge(Node* first,Node *sec);
bool detectCycle(Node *start);
void removeCycle(Node *start);
int midNode(Node *start);



