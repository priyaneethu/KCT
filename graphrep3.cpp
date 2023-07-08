#include<iostream>
#include<stdlib.h>
using namespace std;
struct edge{
      char data;
      edge *next;
};
struct vertex{
      char data;
      edge * right;
      vertex * down;
};
vertex * graphHead;
edge *createEdgeNode( char gd)
{
      edge * newNode;
      newNode = ( edge*)malloc(sizeof(edge));
      newNode -> data = gd;
      newNode -> next = NULL;
      return newNode;
}
vertex* createVertexNode( char gd)
{
          vertex * newNode;
      newNode = ( vertex*)malloc(sizeof(vertex));
      newNode -> data = gd;
      newNode -> right = NULL;
      newNode -> down = NULL;
      return newNode;

}
void createGraph( char v1 , char v2)
{
     vertex * vtptr , *vsafe;
     edge * etptr, *esafe;
     if( graphHead== NULL)
     {
         graphHead = createVertexNode(v1);
         graphHead -> right = createEdgeNode(v2);
         graphHead -> down = createVertexNode(v2);
         graphHead -> down->right = createEdgeNode(v1);

     }
     else{
.
        for( vtptr = graphHead ; vtptr != NULL ; vsafe = vtptr,
                                                 vtptr = vtptr->down)
              if( vtptr -> data == v1) break;
       if( vtptr )
       {
           for( etptr= vtptr->right ;etptr !=NULL ; esafe= etptr ,
                                                   etptr = etptr->next);
               esafe -> next = createEdgeNode(v2);
       }
       else
       {
           vsafe -> down = createVertexNode(v1);
           vsafe -> down -> right = createEdgeNode(v2);

       }
     }

}
void displayGraph()
{
    vertex *vtptr;
    edge * etptr;
    for( vtptr= graphHead;vtptr != NULL ; vtptr = vtptr->down)
    {
        cout<<vtptr->data;
        for( etptr= vtptr -> right ; etptr!= NULL; etptr = etptr->next)
            cout<<"->"<<etptr->data<<" ";
        cout<<"\n|\n";
    }

}
int main()
{
     int noOfVertices , noOfEdges;
     cin>>noOfVertices>>noOfEdges;
     char input[noOfEdges][2];
     int i;
     for( i = 0 ; i < noOfEdges ; i++)
           cin>>input[i][0]>>input[i][1];
     for( i = 0 ; i < noOfEdges ; i++)
     createGraph(  input[i][0] , input[i][1]);
      displayGraph();
}
/*
8 12
A B
A C
A D
B E
B C
B F
C F
D G
E F
E H
F H
G H

*/
