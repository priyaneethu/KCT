#include<iostream>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int count =1,i;
//    this     is
    for( i = 0; i < str.length() ;i++)
    {
        if( str[i] ==' ')
        {
            count++;
            while( str[i] == ' ')
              i++;


        }

    }
    cout<<count;
}
