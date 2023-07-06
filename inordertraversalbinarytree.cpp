#include<iostream>
using namespace std;
struct treeNode{
    treeNode * left;
    int data;
    treeNode *right;
};
struct stackNode{
    treeNode * data;
    stackNode * next;  
};
stackNode * top;
stackNode * createStackNode( treeNode * data)
{
    stackNode * newNode;
    newNode =(stackNode *)malloc( sizeof(stackNode));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
void push( treeNode * data)
{
     stackNode * newNode = createStackNode(data);
    if( top == NULL)
       top = newNode;
    else
    {
        newNode -> next = top;
        top = newNode;
    }   
}
treeNode * pop()
{
    if( top == NULL)
       return NULL;
    else{
        treeNode * safe;
        safe = top -> data;
        top = top ->next;
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
void inorderDisplay( treeNode * root)
{
   treeNode * tptr , *curr;
   tptr = root;
while(1)
{
   for( ;  tptr ; tptr = tptr->left)
      push(tptr);

  while( 1){
    if( top == NULL) break;
   curr = pop();
   cout<<curr -> data<<" ";
   if(curr->right){
   push(curr->right);
   tptr = curr->right->left;
   break;
   }
  }
   if( top == NULL)
      break;
  }
}
int main(){
    treeNode * root;
    root = createNewNode(10);
    root->left = createNewNode(20);
    root -> right = createNewNode(30);
    root->left -> left =  createNewNode(40);
    root -> left -> left -> left = createNewNode(50);
   inorderDisplay( root);
}
