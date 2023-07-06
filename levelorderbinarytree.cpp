#include<iostream>
using namespace std;
struct treeNode{
    treeNode * left;
    int data;
    treeNode *right;
};
struct queueNode{
    treeNode * data;
    queueNode * next;  
};
queueNode * front ,* rear;
queueNode * createQueueNode( treeNode * data)
{
    queueNode * newNode;
    newNode =(queueNode *)malloc( sizeof(queueNode));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
void enqueue( treeNode * data)
{
     queueNode * newNode = createQueueNode(data);
    if( front == NULL)
       front = rear  = newNode;
    else
    {
        rear -> next = newNode;
        rear= newNode;
    }   
}
treeNode * dequeue()
{
    if( front== NULL)
       return NULL;
    else{
        treeNode * safe;
        safe = front -> data;
        front = front ->next;
        return safe;
    }   
}
treeNode * createNewNode( int gd)
{
    treeNode * newNode;
     newNode =(treeNode * )malloc(sizeof(treeNode));
    newNode -> left = newNode -> right = NULL;
    newNode -> data = gd;
    return newNode;
}
void levelOrderDisplay( treeNode * root)
{
     enqueue( root);
    treeNode * deq;
while( front)
{
deq =dequeue();
if( deq == NULL) break;
cout<< deq ->data<<" ";
if( deq -> left)
   enqueue(deq->left);
if( deq -> right)
    enqueue(deq -> right);
}       

}


int main(){
    treeNode * root;
    root = createNewNode(10);
    root->left = createNewNode(20);
    root -> right = createNewNode(30);
    root->left -> left =  createNewNode(40);
    root -> left -> left -> left = createNewNode(50);
   levelOrderDisplay( root);
 }
