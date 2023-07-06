#include<iostream>
using namespace std;
struct Node{
    Node * left;
    int data;
    Node *right;
};
Node * root;
Node * createNewNode( int gd)
{
    Node * newNode;
    newNode =(Node * )malloc(sizeof(Node));
    newNode -> left = newNode -> right = NULL;
    newNode -> data = gd;
    return newNode;
}

void LPR( Node * curr) // inorder
{
    if( curr == NULL) return ;
    else{
        LPR(curr->left);
        cout<<curr->data<<" ";
        LPR(curr->right);
    }
}

void PLR( Node * curr) // preorder
{
    if( curr == NULL) return ;
    else{
        cout<<curr->data<<" ";
        PLR(curr->left);
        PLR(curr->right);
    }
}
void LRP( Node * curr) // inorder
{
    if( curr == NULL) return ;
    else{
        LRP(curr->left);
        LRP(curr->right);
                cout<<curr->data<<" ";

    }
}

int main()
{
    root = createNewNode(10);
    root->left = createNewNode(20);
    root -> right = createNewNode(30);
    root->left -> left =  createNewNode(40);
    root -> left -> left -> left = createNewNode(50);
  LPR(root);
  cout<<"\n";
  PLR(root);
  cout<<"\n";
  LRP(root);
  
}