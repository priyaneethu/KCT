#include<iostream>
using namespace std;
struct Node{
    int data;
    Node * next;
};
Node * top;
Node * createNewNode( int gd)
{
    Node * newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = gd;
    newNode -> next = NULL;
    return newNode;
}
void push( int gd)
{
    Node * newNode;
    newNode = createNewNode(gd);
    if(top ==NULL)
       top= newNode;
    else{
        newNode -> next = top;
        top = newNode;
    }   
}
int pop(){
    Node * safe;
    if( top == NULL)
       return -1;//underflow
    else{
        safe = top;
        top = top -> next;
        return safe->data;
    }
}
int main()
{
    int num;
    while( cin >> num)
        push(num);
    while(top !=NULL)
    cout<<pop()<<" "; 

}