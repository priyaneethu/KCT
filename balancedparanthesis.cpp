#include<iostream>
using namespace std;
struct Node{
    char data;
    Node * next;
};
Node * top;
Node * createNewNode( char gd)
{
    Node * newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = gd;
    newNode -> next = NULL;
    return newNode;
}
void push( char gd)
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
char pop(){
    Node * safe;
    if( top == NULL)
       return 'a';//underflow
    else{
        safe = top;
        top = top -> next;
        return safe->data;
    }
}
char peek()
{
    if(top != NULL)
    return top->data;
    else return -1;
}
int isEmpty(){
    if( top == NULL)
      return 1;
    else return 0;  
}
int main()
{
    string str;
    cin>>str;
    int i;
    for( i = 0 ; i < str.length() ;i++)
    {
      if( str[i]=='(' || str[i]=='{' || str[i]=='[')
         push(str[i]);
      else{
        char popchar = pop();
        if( popchar =='a'){
            break;
        }
        if( popchar =='(' && str[i]!=')'){
            break;
        }
        else if( popchar =='{' && str[i]!='}'){
            break;
        }
         else if( popchar =='[' && str[i]!=']'){
           break;
        }
      }   
    }
    if( i == str.length() && top == NULL)
       cout<<"valid";
    else
    cout<<"Invalid";   
}