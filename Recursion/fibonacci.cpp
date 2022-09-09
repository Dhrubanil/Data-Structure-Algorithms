#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
int fibonacci(int n){
    if(n==1){
        return 0;
        // arr.push_back(0);
    }
    if(n==2){
        return 1;
        // arr.push_back(1);
    }
    return fibonacci(n-1)+fibonacci(n-2);
};

int main(){
    int n;
    cin>> n;
    cout<<fibonacci(n)<<endl;
}
