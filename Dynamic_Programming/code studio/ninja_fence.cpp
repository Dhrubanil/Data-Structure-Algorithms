#include<bits/stdc++.h>
using namespace std;
#define MOD 100000007

// formula f(n) = (f(n-2) * (k-1)) + (f(n-1) * (k-1))

long long int waysByMem(int n, int k, vector<long long int> &dp){
    if(n==1){
        dp[n] = k;
        return dp[n];
    }

    if(k==1){
        return n;
    }
    if( n == 2){
        return k*k;
    }
    if(dp[n]!= -1){
        return dp[n];
    }

    dp[n] = ((((k-1)*waysByMem(n-2,k,dp)) % MOD) + (((k-1)*waysByMem(n-1,k,dp)) % MOD)) %MOD;
    return dp[n];
}

long long int waysByTab(int n, int k){

    if(k==1){
        return n;
    }

    vector<long long int> dp(n+1);
    dp[1] = k;
    dp[2] = k*k;
    for(int i=3;i<=n; i++){
        dp[i] = (( ((k-1) * dp[i-2]) % MOD ) + ( ((k-1) * dp[i-1]) % MOD )) % MOD;
    }
    
    return dp[n];
}

long long int waysBySc(int n, int k){

    if(k==1){
        return n;
    }

    vector<long long int> dp(n+1);
    long long int prev2 = k;
    long long int prev1 = k*k;
    if(n==1){
        return prev2;
    }
    for(int i=3;i<=n; i++){
        long long int ans  = ( ( ( (k-1) * prev2 ) % MOD ) + ( ( (k-1) * prev1) % MOD ) ) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    
    return prev1;
}

long long int numberOfWays(int n, int k) {
    // Write your code here.
    // vector<long long int> dp(n+1, -1);
    // long long int ans = waysByMem(n,k,dp);

    // long long int ans = waysByTab(n,k);

    long long int ans = waysBySc(n,k);
    return ans;
}

int main(){
    int n = 1;
    int k = 2;
    cout<< numberOfWays(n,k)<<endl;
}