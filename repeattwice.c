#include<stdio.h>
int main()
{
    int n,i, j , count=0;
    scanf("%d",&n);
    int arr[n];
    for( i =0 ; i < n ;i++)
      scanf("%d",&arr[i]);
    int xor = 0;
    for( i = 0; i < n; i++)
       xor ^= arr[i];
    printf("%d", xor);


    /*     
    for( i = 0 ; i < n ; i++)
    {
      count = 0;
      for( j = 0; j < n ; j++)
         if( arr[i] == arr[j])
             count++;
      if( count == 1) {
        printf("%d" , arr[i]);
        break;
      }
    }*/  
}