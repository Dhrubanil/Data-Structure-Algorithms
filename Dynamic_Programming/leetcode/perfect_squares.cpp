#include<bits/stdc++.h>
using namespace std;

int numSquaresByMem(int n, vector<int>&dp) {
    if(n==0){
        return 0;
    }
    int ans = INT_MAX;
    if(dp[n]!=-1){
        return dp[n];
    }
    for(int i=1; i*i<=n;i++){
        ans = min(ans,1+numSquaresByMem(n-(i*i),dp));
    }
    dp[n] = ans;
    return dp[n];
}

int numSquares(int n) {
    
    vector<int> dp(n+1,-1);
    int ans = numSquaresByMem(n,dp);
    return ans;
}

int main(){
    long long int n= 53;
    cout<<numSquares(n)<<endl;
}