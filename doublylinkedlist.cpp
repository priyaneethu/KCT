#include<iostream>
using namespace std;
struct Node{
    Node * prev;
    int data;
    Node * next;
};
Node * head , *tail;
void insertAtBegin( int gd)
{
     Node * newNode ;
     newNode  =(Node*) malloc(sizeof(Node));
     newNode-> data = gd;
     newNode -> next = NULL;
     newNode -> prev = NULL;
     if( head == NULL)
        head = tail = newNode;
     else{
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
     }   

}
void forwardDisplay()
{
     Node * tptr;
     for( tptr = head; tptr != NULL ; tptr= tptr->next)
        cout<< tptr -> data<<" ";
}
void backwardDisplay(){
    Node * tptr;
    for( tptr = tail ; tptr != NULL ; tptr = tptr -> prev)
       cout<<tptr->data <<" "; 
}
void insertAtMiddle( int pos , int gd)
{
    Node * tptr , *newNode;
    int i ;
    newNode = (Node *)malloc( sizeof(Node));
    newNode -> data = gd;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    for( i = 1, tptr = head ; i < pos&&tptr != NULL ; i++,
                                           tptr=tptr->next);
    newNode -> prev = tptr->prev;
    newNode -> next = tptr;
    tptr->prev->next = newNode;
    tptr->prev = newNode;



}
void insertAtEnd(int gd)
{
       Node * tptr , *newNode;
       newNode = (Node *) malloc(sizeof(Node));
       newNode ->data = gd;
       newNode -> prev = NULL;
       newNode -> next = NULL;
       if( tail== NULL)
         head = tail = newNode;
      else
      {
        newNode -> prev = tail;
        tail -> next = newNode;
        tail = newNode;
      }   
}




int main()
{
   int num;
   for( num = 10; num < 20 ; num+=2)
      insertAtBegin(num);
   forwardDisplay(); 
   cout<<"\n\n";
 //  insertAtMiddle(3,100);
 insertAtEnd(100);
   forwardDisplay();   

}