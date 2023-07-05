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
    else return '$';
}
int isEmpty(){
    if( top == NULL)
      return 1;
    else return 0;  
}
int isOperator( char ch)
{
    if( ch == '+'||ch=='-'||ch=='*'||ch=='/')
      return 1;
    else return 0;  
}

int precedence( char op)
{
    switch(op)
    {
        case '+':
        case '-': 
                  return 1;
        case '*':
        case '/':
                return 2;
    }
}
int main(){
    string infix;//2-3*7+6/3*5-4+3
    cin>>infix;
    string postfix="";
    int i;
    for( i = 0 ; i < infix.length();i++)
    {
        if( isOperator(infix[i])==1)
        {
                char topOperator = peek();
                while(top!=NULL&& precedence(topOperator) >= precedence(infix[i]))
                {
                       postfix = postfix+ pop();
                       topOperator = peek();
                }
                
                    push(infix[i]);
                
        }
        else{
            postfix = postfix +infix[i];
        }
    }
    while( isEmpty()==0)
    {
        postfix = postfix+ pop();
    }
  cout<<postfix;
    
}