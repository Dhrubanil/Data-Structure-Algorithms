#include<bits/stdc++.h>
using namespace std;


// step-1 top-down + memorizarion
int solve1(int n,vector<int>&dp){
    if(n==0 || n==1){
		dp[n] = 1;
		return dp[n];
    }
    
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = solve1(n-1,dp)+solve1(n-2,dp); 
    return dp[n];
}

// step-2 Bottom-up + tabulization
int solve2(int n){
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<=n ; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// step-3 space optimisation
int solve3(int n){
    int prev1 = 1;
    int prev2 = 1;
    for(int i = 2; i<=n ; i++){
        int current = prev1+prev2;
		prev2 = prev1;
		prev1 = current;
    }
    return prev1;
}


int climbStairs(int n) {
    vector<int> dp(n+1,-1);
    return solve3(n);
}

int main(){
	cout<<climbStairs(3)<<endl;
}