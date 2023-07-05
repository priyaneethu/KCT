#include<iostream>
using namespace std;
class Queue
{
    public:
struct Node
{
    int data;
    Node * next;
};
Node * front=NULL , *rear=NULL;
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
};

Queue q1,q2;
int pop(){
while( q1.front != q1.rear)
q2.enqueue(q1.dequeue());
int retData = q1.dequeue();
while( q2.front)
q1.enqueue(q2.dequeue());
return retData;

}
int main()
{
    int num;
    
    while(cin>>num)
       q1.enqueue(num) ;
  cout<<pop();
  cout<<"\n"<<pop();
       
}