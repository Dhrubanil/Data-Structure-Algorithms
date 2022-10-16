#include<bits/stdc++.h>
using namespace std;

// step-1 top-down + memorizarion

int solve1(vector<int> &cost,int n,vector<int> &dp){
    // base case
    if(n == 0 || n==1){
        dp[n] = cost[n];
        return dp[n];
    }

    // step3 
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = min(solve1(cost, n-1,dp),solve1(cost, n-2,dp))+cost[n];
    return dp[n];
}

// step-2 Bottom-up + tabulization
int solve2(vector<int> &cost,int n){
    vector<int> dp(n+1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i = 2; i<n ; i++){
        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}


// step-3 space optimisation
int solve3(vector<int> &cost,int n){
    vector<int> dp(n+1);
    int prev2 = cost[0];
    int prev1 = cost[1];
    for(int i = 2; i<n ; i++){
        int current = cost[i] + min(prev1,prev2);
        prev2 = prev1;
        prev1 = current;
    }
    return min(prev1,prev2);
}



// step-5 worst step
// Going Lower stairs to upperstairs
int solve5(vector<int> &cost,int stairsIndex,vector<int> &dp){
    if(stairsIndex == cost.size()){
        
        return 0;
    }
    if(stairsIndex == cost.size()-1){

        dp[stairsIndex] = cost[stairsIndex];
        return dp[stairsIndex];
    }
    if(dp[stairsIndex] != -1){
        return dp[stairsIndex];
    }
    dp[stairsIndex] = min(solve5(cost,stairsIndex+1,dp),solve5(cost,stairsIndex+2,dp))+cost[stairsIndex];
    return dp[stairsIndex];

}

// Going Lower stairs to upperstairs
int minCostClimbingStairs(vector<int> &cost){
    vector<int> dp(cost.size()+1,-1);
    int n = cost.size();

    // step1
    int mincost = min(solve1(cost,n-1,dp),solve1(cost,n-2,dp));


    // step2
    // int mincost = min(solve2(cost,n),solve2(cost,n));


    // step3
    // int mincost = min(solve3(cost,n),solve3(cost,n));


    // step 5
    // int mincost = min(solve5(cost,0,dp),solve5(cost,1,dp));
    
    
    return mincost;
}

int main(){
    vector<int>cost{1,100,1,1,1,100,1,1,100,1};
	cout<<minCostClimbingStairs(cost)<<endl;
}