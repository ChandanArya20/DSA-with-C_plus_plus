#include <iostream>
#include <climits>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(){data=0; next=nullptr;}
    Node(int data)
    {
        this->data=data;
        next=nullptr;
    } 
};
class Linked_list
{
private:
    Node *head;
public:
    Linked_list(){head=NULL;}
    Linked_list(int data)
    {
        head=new Node(data);
    }
    void display();
    void Rdisplay(Node *p);
    int length();
    int Rlength();
    int sum();
    int Rsum();
    int max();
    int min();
    int search(int key);
    void insertAtBeg(int data);
    void insertAtEnd(int data);
    void insertAtLoc(int pos,int data);
    void insertAtSorted(int data);
    void delData(int pos); 
    void removeDuplicate();
    void reverse();
    Node *concate(Node *second);
    Node *merge(Node *sec);
    bool detectCycle();
    void removeCycle();
    int midNode();
};



