#include<iostream>
using namespace std;
int main()
{
     int M,N,row, col;
     cin>>M>>N;
     int mat[M][N];
     for( row = 0 ; row < M ; row++)
        for( col = 0 ; col < N ; col++)
            cin >> mat[row][col];
     //row traversal
   /*  for( row = 0 ; row < M ; row++ , cout<<"\n")
        for( col = 0; col < N ; col++)
            cout << mat[row][col]<<" ";   

     //col traversal           
     for( col = 0; col < N ; col++, cout<<"\n")
      for( row = 0 ; row < M ; row++ )
            cout << mat[row][col]<<" "; 

     int stRow=0 ,stCol=N-1;
     for( ; stCol >= 0; stCol--){
     for( row = stRow , col = stCol ; row<M&& col < N ; row++,col++ )
         cout<<mat[row][col]<<" ";
     cout<<"\n";
     }
     for(stCol = 0,stRow = 1 ;  stRow< M; stRow++){
     for( row = stRow , col = stCol ; row<M&& col < N ; row++,col++ )
         cout<<mat[row][col]<<" ";
     cout<<"\n";
     }
     */
     int stRow , stCol;
    for( stRow = 0 , stCol = 0 ; stCol < N ; stCol++)
    {
          for( row = stRow , col = stCol ; row < M && col >= 0 ; row++,col--)  
             cout<<mat[row][col]<<" ";
          cout<<"\n";   
    }
    for( stRow = 1 , stCol = N-1; stRow < M; stRow++)
    {
          for( row = stRow , col = stCol ; row < M && col >= 0 ; row++,col--)  
             cout<<mat[row][col]<<" ";
          cout<<"\n";   
    }
    

    


}