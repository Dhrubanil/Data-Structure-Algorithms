#include<bits/stdc++.h>
using namespace std;
#define MOD 100000007
// formula f(n) = [n-1] * (f[n-1] + f[n-2])
// *place 0 to any place then we have remaining (n-1) space
// place 0 to which place place that element to 0's index;
// place 0 to which place not place that element to 0's index;

long long int countDerangementsNorm(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    long long int ans = (((n-1)%MOD)*((countDerangementsNorm(n-1)%MOD)+ (countDerangementsNorm(n-2)%MOD)))% MOD;
    return ans;
}

long long int countDerangementsByMem(int n,vector<long long int> &dp){
    if(n==1){
        dp[1] = 0;
        return dp[n];
    }
    if(n==2){
        dp[n] =1;
        return dp[n];
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    long long int ans = (((n-1)%MOD)*((countDerangementsByMem(n-1,dp)%MOD)+ (countDerangementsByMem(n-2,dp)%MOD)))% MOD;
    dp[n] = ans;
    return dp[n];
}

long long int countDerangementsByTab(int n){
    vector<long long int> dp(n+1,0);
    dp[0] = 0;
    dp[1]=0;
    dp[2] = 1;
    for(int i = 3;i<=n ; i++){
        // dp[i] = (((i-1)%MOD)*((dp[i-1]%MOD)+ (dp[i-2]%MOD)))% MOD;
        long long int first = dp[i-1];
        long long int second = dp[i-2]%MOD;
        long long int sum = (first+second)%MOD;
        dp[i] = ((i-1)*sum) % MOD;
    }
    return dp[n];
}

long long int countDerangementsByTabSc(int n){
    long long int prev2=0;
    long long int prev1 = 1;
    for(int i = 3;i<=n ; i++){
        // dp[i] = (((i-1)%MOD)*((dp[i-1]%MOD)+ (dp[i-2]%MOD)))% MOD;
        cout<<i<<endl;
        long long int first = prev1%MOD;
        long long int second = prev2%MOD;
        long long int sum = (first+second)%MOD;
        long long int ans = ((i-1)*sum) % MOD;
        prev2 = prev1;
        prev1 = ans;

    }
    return prev1;
}

long long int countDerangements(int n) {
    // Write your code here.
    // long long int ans = countDerangementsNorm(n);
    vector<long long int> dp(n+1,-1);

    // long long int ans = countDerangementsByMem(n,dp);

    // long long int ans = countDerangementsByTab(n);

    long long int ans = countDerangementsByTabSc(n);
    
    return ans;
}


int main(){
    int n= 1;
    cout<<countDerangements(n)<<endl;
}