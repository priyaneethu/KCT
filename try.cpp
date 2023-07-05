#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr;
    int val;
    for(auto i =0 ; i < 5 ; i++)
    {
       cin>>val; 
      arr.push_back(val);
    }cout<<"hello";
    for(auto &i:arr)
      cout<<i<<" ";

}