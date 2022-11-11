#include<bits/stdc++.h>
using namespace std;
#define MOD 100000007

long long int nCrByMem(int n,int r, vector<long long int> &dp){
    if(n==0){
        dp[0] = 1;
        return 1;
    }
    if(n==1){
        dp[1] = 1;
        return 1;
    }
    if(dp[n]!=-1) {
        return dp[n];
    }
    dp[n] = n * nCrByMem(n-1,r,dp);
    cout<<dp[n]<<endl;
    return dp[n];
}

int nCr(int n, int r){
    // code here
    if(r>n){
        return 0;
    }
    vector<long long int> dp(n+1,-1);
    int ans = (nCrByMem(n,r, dp)/(dp[r]*dp[n-r]))% MOD;
    return ans;
}

int main(){
    int n = 15;
    int r= 3;
    cout<<nCr(n,r)<<endl;
}