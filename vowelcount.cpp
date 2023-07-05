#include<iostream>
using namespace std;
int main(){
   string str;
  // cin>>str;
  getline(cin,str);
 // getline()
   int i,vowel=0 , n =str.length();
   for( i = 0 ; i < n ; i++)
   {
      if( str[i] =='a' || str[i] =='i' ||str[i] =='o' ||str[i] =='u'||str[i] =='e')
         vowel++;

   }
   cout<<vowel;


}
