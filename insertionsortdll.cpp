#include<iostream>
using namespace std;
struct Node{
    Node * prev;
    int data;
    Node * next;
};
Node * head , *tail;
Node * createNewNode( int gd)
{
    Node * newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = gd;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    return newnode;
}
void insertSortedOrder( int gd)
{
   Node * newNode ,*tptr;
    newNode = createNewNode(gd);
    if( head == NULL)
    
        head = tail = newNode;
    else{
    for( tptr = head ; tptr != NULL&&tptr->data < newNode->data ; tptr = tptr->next);
    if( tptr == head)//begin
    {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
    else if( tptr == NULL)//end
    {
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
    }
    else{  //middle
          newNode -> prev = tptr->prev;
          newNode -> next =tptr;
          tptr->prev -> next = newNode;
          tptr->prev = newNode;
    }
    }
}
void forwardDisplay()
{
     Node * tptr;
     for( tptr = head; tptr != NULL ; tptr= tptr->next)
        cout<< tptr -> data<<" ";
}

int main()
{
   int d;
   while(cin>>d)
   {
     insertSortedOrder(d);
   }
   forwardDisplay();  
}