#include<stdio.h>
int main()
{
    int n,i, up , dp ,j;
    scanf("%d",&n);
    int arr[n];
    for( i =0 ; i < n-1 ;i++)
      scanf("%d",&arr[i]);
   for(dp = 1 ; dp < n ; dp++)
   {
      for( i = 0 ; i < dp; i++)
         if( arr[i] == arr[dp])
            break;
   }  
   up = dp;
   for( j = dp+1; j< n ; j++ )
   {
    for( i = 0 ; i < up ; i++)
       if( )
   }

}