#include<stdio.h>
#include<math.h>
int main(){
  long long  int num;
   scanf("%lld", &num); //61728394506
   long long int factor , till;
   till = sqrt(num);
   for(factor = 1; factor <= till; factor++)
      if( num % factor == 0)
          printf("%lld ", factor);
    if( till *till == num)
        till = till-1;
    for( factor =till ; factor >=1 ; factor--)
        if( num % factor ==0 )
            printf("%lld ", num/factor);

}