#include<bits/stdc++.h>
using namespace std;

// step1 Top down + memorization
int solve1 (vector<int>& coins, int amount,vector<int>& dp){
    // Base case
    if(amount == 0){    
        return 0;
    }

    if(amount < 0){    
        return INT_MAX;
    }

    if(dp[amount] != -1){
        return dp[amount];
    }
    int mini = INT_MAX;
    for(int i = 0 ;i<coins.size();i++){
        int ans = solve1(coins , amount - coins[i], dp);
        if(ans!= INT_MAX){
            mini = min(mini, ans+1);
        }
    }
    dp [ amount ] = mini;
    return dp [ amount ];
    
}


// Tabulization
int solve2(vector<int>& coins, int amount){

    vector<int> dp(amount+1,INT_MAX);

    dp[0] = 0;
    // creating ans for every amount
    for(int i=1;i<=amount;i++){
        for(int j=0;j<coins.size();j++){
            if(i- coins[j]>=0 && dp[i - coins[j]] != INT_MAX){
                int ans = 1+dp[i- coins[j]];
                dp[i] = min(dp[i],ans);
            }
        }

    }
    // if(dp[amount] == INT_MAX){
    //     return -1;
    // }
    return dp[amount];
}


int coinChange(vector<int>& coins, int amount) {

    vector<int> dp(amount+1,-1);
    // int ans = solve1(coins,amount,dp);
    int ans = solve2(coins,amount);
    if(ans == INT_MAX){
        return -1;
    }else{
        return ans;
    }

}


int main(){
    vector<int> coins{2};
    int amount = 3;
    cout<<coinChange(coins, amount)<<endl;
}