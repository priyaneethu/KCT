#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;
};
Node * head;
Node * createNewNode( int gn)
{
    Node * newNode ;
    newNode = (Node*)malloc(sizeof(Node));
    newNode ->data = gn;
    newNode->next = NULL;
    return newNode;
}
void insertAtBegin(int gn)
{
    Node * newNode,*tptr;
    newNode = createNewNode( gn);
    if( head == NULL)
    {
           head = newNode;
           newNode -> next = head;
    }      
    else{
        for( tptr = head ; tptr->next != head ; tptr = tptr->next);
        newNode->next = head;
        head = newNode;
        tptr->next=head;

    }
}
void display()
{
    Node * tptr;
    for( tptr = head ; tptr->next != head ; tptr= tptr->next)
       cout<<tptr->data<<" ";
    cout<<tptr->data;
}
int main()
{
    int d;
    while(cin>>d)
      insertAtBegin(d);
    display();
}