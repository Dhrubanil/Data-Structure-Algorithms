#include<iostream>
using namespace std;

void swap(int &p, int &q){
int newp = p;
cout<<p<<" "<<q << " "<<endl;
p=q;
cout<<p<<" "<<q <<" "<<&q<<endl;
// *q=newp;
// cout<<p<<" "<<q << " "<<*p<<" "<<*q<< &p<<" "<<&q<<endl;
}
// void swap(int *p, int* q){
// int newp = *p;
// cout<<p<<" "<<q << " "<<*p<<" "<<*q<< &p<<" "<<&q<<endl;
// *p=*q;
// cout<<p<<" "<<q << " "<<*p<<" "<<*q<< &p<<" "<<&q<<endl;
// *q=newp;
// cout<<p<<" "<<q << " "<<*p<<" "<<*q<< &p<<" "<<&q<<endl;
// }

int main(){
    // int 7
    // int* a=new int(5);
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    // for(int i=0;i<n;i++){
    //     cout<<a[i];
    // }
    // cout<<endl;
    // cout<<sizeof(a)/sizeof(int);

    int a = 7;
    int b= 8;
    int *p = &a;
    int *q = &b;
    // swap(p,q);
    swap(a,b);
    // cout<<p<<" "<<q << " "<<*p<<" "<<*q<< " "<<&p<<" "<<&q<<endl;
    
}