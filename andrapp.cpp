#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    string appName;
    Node * next;
};
struct apps{
    char ch;
    Node * head;
};

Node * createNewNode( string name)
{
    Node * newNode;
    newNode = (Node * )malloc(sizeof(Node));
    newNode -> appName = name;
    newNode -> next = NULL;
    return newNode;
}


int main()
{
   apps order[26];
   int  i,index;
   Node * newNode;
   for( i = 0; i < 26 ; i++)
   {
       order[i].ch = 'A'+i;
       order[i].head = NULL;
   }
   string appName ,dummy;
 for( int j = 0 ; j < 10 ; j++)
 {
   cin>>appName;
  // cout<<appName;
   index = appName[0]-'A';
   newNode = createNewNode(appName);
   if(order[index].head == NULL)
       order[index].head = newNode;
    else{
        Node * tptr, *safe;
        for( tptr = order[index].head  ; tptr!= NULL ;safe = tptr,
                                      tptr = tptr ->next ){
             if( tptr -> appName.compare( newNode->appName) > 0)
                break;
        }
        if( tptr == order[index].head) // insert at begin
        {
            newNode -> next = order[index].head;
            order[index].head = newNode;
        }
        else if( tptr == NULL) // insert at end
        {
           safe -> next = newNode;
        }
        else{
            //mid
            safe -> next = newNode;
            newNode -> next = tptr;
        }
    }
}

   Node * tptr;
   char ch;
   cin>>ch;
   i = ch-'A';
   cout<<order[i].ch<<" ";
    for( tptr = order[i].head ; tptr != NULL ; tptr = tptr->next)
      cout<< tptr->appName<<" ";
    cout<<"\n";




}
/*
Abilash
Swetha
Yashwanth
Harish
Subasree
Kaviya
Tharun
Sarooth
Bharath
Thilak
Sam
Sandhiya
Manoj
Uma
Sheeba

*/
