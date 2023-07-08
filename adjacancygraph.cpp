#include<iostream>
using namespace std;
int main()
{
int noOfVertices , noOfEdges,i,j , row,col;
cin>>noOfVertices;
cin>>noOfEdges;
char edges[noOfEdges][2];
for( i = 0 ; i < noOfEdges ; i++)
   cin>>edges[i][0]>>edges[i][1];
for( i = 0 ; i < noOfEdges ; i++)
   cout<<edges[i][0]<<edges[i][1]<<"\n";
      
    
    int adjacancyMatrix[noOfVertices][noOfVertices];
    for( i = 0 ; i < noOfVertices ; i++)
       for( j = 0;  j< noOfVertices ; j++)
           adjacancyMatrix[i][j] = 0;
   for( i = 0 ; i < noOfEdges ; i++)
   {
       row= edges[i][0] -'A';
       col = edges[i][1] - 'A';
       adjacancyMatrix[row][col] = 1;
       adjacancyMatrix[col][row] = 1;   
   }  
   for( row = 0 ; row < noOfVertices ; row++ , cout<<"\n")
      for( col = 0 ;col < noOfVertices ; col++)
         cout<<adjacancyMatrix[row][col] <<" "; 
}