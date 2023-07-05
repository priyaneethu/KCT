#include<iostream>
class Node{
    public: 
    int data;
    Node * next;
      Node(int num)
      {
        data = num;
        next = NULL;
      }
      void displayNode()
      {
        std::cout<<data<<" ";
      }
      
};

class Linkedlist{
    Node * head=NULL;
    public:
    void insertNodeAtBegin( Node * givenNode)
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
    void insertNodeAtEnd( Node * givenNode)
    {
        Node * tptr;
        if( head== NULL)
           head = givenNode;
        else{   
        for( tptr = head ; tptr -> next != NULL ; tptr=tptr->next);
        tptr->next = givenNode;
        }
    }
    void insertNodeAtMiddle( int pos , Node * givenNode)
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
    void deleteNode( int delValue)
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

    int searchNode( int val)
    {
        Node * tptr;
        int pos;
        for( tptr = head,pos = 1 ; tptr != NULL ;tptr = tptr->next , pos++ )
            if( tptr -> data == val)
              return pos;
        return -1;      
    }
    int length()
    {
        int len =0;
        Node * tptr;
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
    void reverseLinkedList(){
        Node * me , *mynext , *myprev;
        for( me = head , myprev= NULL;  me != NULL; )
        {
                mynext = me -> next;
                me->next = myprev;
                myprev = me;
                me = mynext;

        }
        head = myprev;
    }


};
int main()
{
Linkedlist ll;

 for( int i = 10 ; i <60 ; i+=5){
     Node *newNode = new Node(i);
       ll.insertNodeAtBegin(newNode);

 }
 ll.displayLL();
 std::cout<<"\n";
 ll.reverseLinkedList();
 ll.displayLL();
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