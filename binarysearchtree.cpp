#include<iostream>
using namespace std;
struct Node{
     Node * left;
     int data;
     Node * right;

};
Node * createNewNode( int gd)
{
    Node * newNode;
    newNode =(Node*)calloc(1,sizeof(Node));
    newNode -> data = gd;
    return newNode;
}
Node * root;
void createBst( int gd)
{
    Node * newNode, *tptr, *safe;
    newNode = createNewNode(gd);

    if( root == NULL)
       root = newNode;
    else{
       for( tptr = root ; tptr ; )
       {
          safe = tptr;
          if( tptr-> data > newNode->data)
             tptr=  tptr -> left;
           else 
              tptr=  tptr -> right;  
       }
     //for( tptr = root ; tptr ; safe = tptr,tptr = tptr -> data>  newNode ->data?tptr->left : tptr->right);
        //)
        if( safe ->data > newNode ->data)
            safe ->left = newNode;
        else
           safe -> right = newNode;    

    }   
}
void inorderDisplay(  Node * curr)
{
   if( curr == NULL) return;
   else{
       inorderDisplay(curr->left);
       cout<<curr -> data <<" ";
       inorderDisplay(curr->right);
   }
  /*if( curr)
  {
    inorderDisplay(curr->left);
       cout<<curr -> data <<" ";
       inorderDisplay(curr->right);
  }*/
}

void deleteNode( int gd)
{
   Node * curr , *currParent=NULL;
   for( curr = root ; curr  ; )
   {

           if( curr -> data == gd)  break;
       currParent = curr;

       curr = curr -> data > gd ? curr -> left:curr->right;
   } 
   if(curr->left ==NULL && curr->right==NULL )//leaf node
   {
      if( curr == root)
         root = NULL;
      else{   
     if( currParent->data  > curr->data)
        currParent ->left = NULL;
     else  currParent ->right = NULL;}
   }
   else if( curr->left && curr -> right){
     Node * tptr,*safe;
     for(safe = curr->right, tptr = curr -> right -> left; tptr ;safe=tptr, tptr = tptr->left);
     safe -> left = curr->left;
     if( curr == root)
         root = curr->right;
     else{    
     if( currParent -> data > curr->data)
        currParent -> left = curr->right;
     else
        currParent -> right = curr->right;   
     }

   }
   else{// single child
    if( curr -> right)
    {
        if( curr == root ){
           root = curr->right;
        }
        else{
       if( currParent ->data > curr->data)
           currParent -> left = curr->right;
       else
          currParent -> right = curr->right;    
        }
    }
    else{
         if( curr== root){
           root = curr->left;
         }
         else{
           if( currParent ->data > curr->data)
           currParent -> left = curr->left;
       else
          currParent -> right = curr->left;    
         }
    }

   }

   
}
int main()
{
     int num;
    while(1){
       cin>>num;
       if( num == -1) break;
       createBst(num);
    }
    inorderDisplay(root);
    cin>>num;
    deleteNode(num);
    inorderDisplay(root);

/*while(cin>>num)
   createBst(num);
 inorderDisplay(root);
 cin>>num;
 deleteNode(num);*/  
}