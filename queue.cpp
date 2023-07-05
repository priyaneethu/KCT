#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;
};
Node * front , *rear;
Node * createNewNode( int gd)
{
    Node * newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = gd;
    newNode -> next = NULL;
    return newNode;
}
void enqueue(int gd)
{
    Node * newNode;
    newNode =createNewNode(gd);
    if( front == NULL)
       front = rear = newNode;
    else
    {
        rear -> next = newNode;
        rear = newNode;
    }   

}
int dequeue(){
    if( front != NULL)
       {
        Node * safe;
        safe = front;
        front = front->next;
        return safe -> data;
       }
       return -1;
}


int main()
{
    int num;
    while(cin>>num)
       enqueue(num) ;
    while(front)
      cout<<dequeue()<<" ";    
}