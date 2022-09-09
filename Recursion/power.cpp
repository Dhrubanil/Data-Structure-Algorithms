#include<bits/stdc++.h>
using namespace std;

int powerWithRecursion(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    if(b%2 == 0){
        return powerWithRecursion(a,b/2) * powerWithRecursion(a,b/2);
    }else{
        return a*powerWithRecursion(a,b/2) * powerWithRecursion(a,b/2); 
    }
}

int main(){
    cout<<powerWithRecursion(3,11)<<endl;
}