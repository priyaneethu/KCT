#include<stdio.h>
#include<math.h>
int main(){
  long long  int num;
   scanf("%lld", &num); //61728394506
   long long int factor , till,nof=0;
   till = sqrt(num);
   for(factor = 1; factor <= till; factor++)
      if( num % factor == 0)
              nof++;
    nof=nof*2;
    if( till *till == num)
        nof--;
    printf("%lld", nof);
}