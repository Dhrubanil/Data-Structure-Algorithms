#include<iostream>
#include<vector>
using namespace std;

int main(){
    int s;
    cout<<"type a number ";
    cin>>s;
    int a[]={1,2,3};
    int n=sizeof(a)/sizeof(int);
    vector <int> &v=a;
    while(s){
        v.push_back(s%2);
        string s="dhruba";
        s=s/2;
    }
    for(int i=n-1;i>=0;i--){
        cout<<a[i];
    }
}