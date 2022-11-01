#include<bits/stdc++.h>
using namespace std;

// solve1
int maxSum(vector<int> &nums , int index){
    if(index < 0){
        return 0;
    }
    if(index==0){
        return nums[0];
    }
    int include =  nums[index]+maxSum(nums,index-2);
    int exclude = maxSum(nums,index-1);
    return max(include,exclude);

}

// solve2
int maxSumByMem(vector<int> &nums , int index, vector<int> &dp){
    if(index < 0){
        return 0;
    }
    if(index==0){
        return nums[0];
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int include =  nums[index]+maxSumByMem(nums,index-2,dp);
    int exclude = maxSumByMem(nums,index-1,dp);
    dp[index] = max(include,exclude);
    return dp[index];

}

// solve3
int maxSumByTab(vector<int> &nums){
    vector<int> dp(nums.size());
    dp[0] =nums[0];

    for(int i=1;i<nums.size();i++){
        int include = nums[i] + dp[i-2];
        int exclude = dp[i-1] + 0;
        dp[i] = max(include,exclude);
    }
    return dp[nums.size()-1];

}

// solve4
int maxSumBySc(vector<int> &nums){
    vector<int> dp(nums.size());
    int prev1 =nums[0];
    int prev2 = 0;

    for(int i=1;i<nums.size();i++){
        int include = nums[i] + prev2;
        int exclude = prev1 + 0;
        int ans = max(include,exclude);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;

}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp(nums.size(),-1);
    // return maxSum(nums,nums.size()-1);

    // return maxSumByMem(nums,nums.size()-1,dp);
    // return maxSumByTab(nums);
    return maxSumBySc(nums);
}

int main(){
    vector<int> v{1 ,2 ,3 ,1 ,3, 5, 8, 1, 9};
    cout<<maximumNonAdjacentSum(v)<<endl;
}