#include<iostream>
template<typename T>class Node{
    public: 
    T data;
    Node <typename T>* next;
      Node(T num)
      {
        data = num;
        next = NULL;
      }
      void displayNode()
      {
        std::cout<<data<<" ";
      }
      
};
template<typename T>
class Linkedlist{
    Node <typename T> * head=NULL;
    public:
    void insertNodeAtBegin( Node<typename T> * givenNode)
    {
        if( head == NULL)
             head = givenNode;
        else{     
            givenNode->next = head;
            head = givenNode;
        }
    } 
    void displayLL()
    {
        Node  * tptr;
        for( tptr = head ;tptr != NULL;tptr = tptr->next )
        std::cout<<tptr -> data<<" ";
    } 
    void insertNodeAtEnd( Node <typename T>* givenNode)
    {
        Node * tptr;
        if( head== NULL)
           head = givenNode;
        else{   
        for( tptr = head ; tptr -> next != NULL ; tptr=tptr->next);
        tptr->next = givenNode;
        }
    }
    void insertNodeAtMiddle( int pos , Node<typename T> * givenNode)
    {
          int i;
          Node * tptr,*safe;
    for( i = 1, tptr= head; i < pos-1 && tptr !=NULL; i++ ,safe=tptr,tptr=tptr->next);
    if( i == pos-1)
    {
        givenNode->next = tptr->next;
        tptr->next = givenNode;
    }
    else{
      safe->next = givenNode;
    }


    }
    void deleteNode( T delValue)
    {
       Node * tptr, *safe;
       for( tptr = head ; tptr !=NULL ;safe = tptr, tptr = tptr->next )
             if( tptr->data == delValue)  break;
    
       if( tptr == head)
           head = tptr->next;
       else if( tptr -> next == NULL)
               safe -> next = NULL;
       else
           safe -> next = tptr -> next;        
       free(tptr);
    }

    int searchNode( T val)
    {
        Node<typename T> * tptr;
        int pos;
        for( tptr = head,pos = 1 ; tptr != NULL ;tptr = tptr->next , pos++ )
            if( tptr -> data == val)
              return pos;
        return -1;      
    }
    int length()
    {
        int len =0;
        Node<typename T> * tptr;
        for( tptr=  head ; tptr!= NULL ; tptr = tptr->next ,len++);
        return len;
    }
    int midPoint( )
    {
      /*  int len = length();
        int mid = len/2;
        int pos;
        Node * tptr;
        for( pos = 0 , tptr = head ; tptr!=NULL&& pos <mid; pos++,tptr=tptr->next );
        return tptr->data;*/
      Node *slow,*fast;
      for( slow = fast = head; fast !=NULL && fast -> next !=  NULL ; 
                         slow = slow->next, fast = fast->next->next);
      return slow -> data;

    }
    void printAlternateNodes(){
          Node *fast;
      for( fast = head; fast !=NULL ; fast = fast->next->next)
            std::cout<<fast->data<<" ";
        
    
    }
    int findNthNodeFromLast(int n)
    {
      /*  int len = length();
        int i;
        Node * tptr;
        n = len - n;
       for(tptr = head , i = 0; tptr&& i < n ; tptr =tptr->next,i++ );
       return tptr->data;  */
       int i;
       Node * slow , *fast;
       for( i = 0, fast = head ; i < n&&fast != NULL ; i++,fast=fast->next);
       for( slow = head ; fast != NULL ; slow = slow->next,fast = fast->next);
       return slow->data;      
    }

};
int main()
{
Linkedlist<int> ll;

 for( int i = 10 ; i <60 ; i+=5){
     Node<int> *newNode = new Node<int>(i);
       ll.insertNodeAtBegin(newNode);

 }
 ll.displayLL();
 std::cout<<"\n";
 //std::cout<<ll.findNthNodeFromLast(5);
 //ll.printAlternateNodes();
 //std::cout<<"\n"<<ll.midPoint();
 //std::cout<<ll.searchNode(100);
  /*
 int num;
for( int i = 0 ; i < 5 ; i++)
{
    std:: cin>> num;
 Node *newNode = new Node(num);
 ll.insertNodeAtEnd(newNode);
}
   ll.displayLL(); 
 /* Node * newNode = new Node(60); 
   ll.insertNodeAtMiddle(3,newNode);

  ll.deleteNode( 50);

  ll.displayLL(); */
}