#include<iostream>
using namespace std;
int main()
{
   string str;
   getline(cin,str);
   int i,ind;
   int countarr[26]={0};
   for( i = 0 ; i < str.length(); i++)
   {
        ind = str[i]-'a';
        countarr[ind]++;//countarr[ind] = countarr[ind]+1
   }
   for( i = 0 ; i < 26 ; i++)
   {
       if( countarr[i] == 0)
          break;
   }
   if( i == 26)
       cout<<"Pangram string";
   else
   cout<<"Not pangram string";


}
