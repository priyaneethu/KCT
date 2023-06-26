#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],i;
    for(  i = 0 ; i < n ; i++)
       scanf("%d",&arr[i]);
    int count = 1 , pos;
    for( pos = 1 ; pos < n ; pos++)
    {
        for( i = 0 ; i < pos ; i++)
           if( arr[i] > arr[pos])
              break;
        if( i == pos)
          count++;      
    }   
    printf("%d",count);


}