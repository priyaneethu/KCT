#include<stdio.h>
#include<math.h>
int main()
{
    int num=7;
    int factor, sof = 0, till;
    till = sqrt(num);
    for( factor =1; factor <= till ; factor++)
    {   
        if( num % factor == 0) //6%1 ==0 
           sof = sof + factor + num / factor;          
    }
   if( till * till == num)
       sof -= till;
   sof-=num;
   if( sof == num)
      printf("%d Yes its perfect number",num);
   else 
   printf("%d is not a perfect square", num);  

}