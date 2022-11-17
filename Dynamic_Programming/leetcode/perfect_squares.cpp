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

int numSquaresByTab(int n) {
    vector<int>dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i=1; i<=n;i++){
        for(int j=1; j*j<=i;j++){
            // cout<<i-(j*j)<<endl;
            dp[i] = min(dp[i],1+dp[i-(j*j)]);
        }
    }
    return dp[n];
}

int numSquares(int n) {
    
    vector<int> dp(n+1,-1);
    // int ans = numSquaresByMem(n,dp);
    int ans = numSquaresByTab(n);
    return ans;
}

int main(){
    long long int n= 5;
    cout<<numSquares(n)<<endl;
}