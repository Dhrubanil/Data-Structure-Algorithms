#include<bits/stdc++.h>
using namespace std;

long int factorial(int n){
    if(n=0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(n=2){
        return 2;
    }
    return n*factorial(n-1)*factorial(n-2);
}

int main(){

cout<<factorial(8)<<endl;
}