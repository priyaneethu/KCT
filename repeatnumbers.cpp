#include<iostream>
using namespace std;
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
     
    void displayLL()
    {
        Node  * tptr;
        for( tptr = head ;tptr != NULL;tptr = tptr->next )
        std::cout<<tptr -> data<<" ";
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
    Linkedlist addTwoLists(Linkedlist l1 , Linkedlist l2)
    {
        l1.reverseLinkedList();
        l2.reverseLinkedList();
        Linkedlist res;
        int carry = 0,temp,rem;
        Node * tptr1 , *tptr2;
        Node * newNode;
        for( tptr1= l1.head , tptr2 = l2.head ;tptr1 != NULL && tptr2 != NULL;tptr1= tptr1 -> next , tptr2 = tptr2->next ){

                temp = carry+tptr1->data + tptr2 -> data;
                rem = temp % 10;
                carry = temp / 10;
                newNode = new Node(rem);
                res.insertNodeAtEnd(newNode);

        }
       while( tptr1 != NULL )
        {
                temp = carry+tptr1->data;
                rem = temp % 10;
                carry = temp / 10;
                newNode = new Node(rem);
                res.insertNodeAtEnd(newNode);
                tptr1 = tptr1 -> next;
        }
        while( tptr2 != NULL )
        {
                temp = carry+tptr2->data;
                rem = temp % 10;
                carry = temp / 10;
                newNode = new Node(rem);
                res.insertNodeAtEnd(newNode);
                tptr2 = tptr2 -> next;
        }
        res.reverseLinkedList();
        return res;
    }



};
int main()
{
 int d;
 Linkedlist l1 , l2 , res;
 Node * newNode;
while(cin>>d){
// cin>>d;
 //if(d == -1) break;
  newNode = new Node(d);
 l1.insertNodeAtEnd(newNode);
}
while(cin>>d){
 //cin>>d;
 //if(d == -1) break;
  newNode = new Node(d);
 l2.insertNodeAtEnd(newNode);
}

res= res.addTwoLists(l1,l2);
res.displayLL();   


}