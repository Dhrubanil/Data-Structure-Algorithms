#include<bits/stdc++.h>
using namespace std;

int maximumRobberyMoney(vector<int>& nums,int index){
	if(index == 0){
		return nums[index];
	}
	if(index < 0){
		return 0;
	}
	int include = nums[index]+maximumRobberyMoney(nums,index-2);
	int exclude = maximumRobberyMoney(nums,index-1);
	return max(include,exclude);
}

int maximumRobberyMoneyMem(vector<int>& nums,vector<int>&dp,int index){
	if(index < 0){
		return 0;
	}
	if(index == 0){
		dp[index] = nums[index];
		return dp[index];
	}
	if(dp[index]!=-1){
		return dp[index];
	}
	int include = nums[index]+maximumRobberyMoneyMem(nums,dp,index-2);
	int exclude = maximumRobberyMoneyMem(nums,dp,index-1);
	dp[index] = max(include,exclude);
	return dp[index];
}
int maximumRobberyMoneyTab(vector<int>& nums){
	vector<int> dp(nums.size());
	dp[0] = nums[0];

	for(int i=1;i<nums.size();i++){
		int include = nums[i]+dp[i-2];
		int exclude = dp[i-1];
		dp[i] = max(include,exclude);
	}

	return dp[nums.size()-1];
}

int maximumRobberyMoneySc(vector<int>& nums){
	vector<int> dp(nums.size());
	int prev1= nums[0];
	int prev2 = 0;

	for(int i=1;i<nums.size();i++){
		int include = nums[i]+prev2;
		int exclude = prev1;
		int curr = max(include,exclude);
		prev2 = prev1;
		prev1= curr;
	}

	return prev1;
}


int rob(vector<int>& nums) {
	int size = nums.size();

	// int ans = maximumRobberyMoney(nums, nums.size()-1);

	// vector<int> dp(size,-1);
	// int ans = maximumRobberyMoneyMem(nums,dp, size-1);

	// int ans = maximumRobberyMoneyTab(nums);

	int ans = maximumRobberyMoneySc(nums);

	return ans;
}

int main(){
	vector<int> v{1,2,3,1};
	cout<<rob(v)<<endl;
}