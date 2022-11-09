#include <bits/stdc++.h> 
using namespace std;



int knapsackByRec(vector<int> weight, vector<int> value, int index, int capacity) {
	// Write your code here
    if(index == 0){
        if(capacity>= weight[index]){
            return value[index];
        }else{
            return 0;
        }
    }
    int include = INT_MIN;
    if(weight[index] <= capacity){
        include = value[index] + knapsackByRec(weight,value,index-1,capacity-weight[index]);
    }
    int exclude = knapsackByRec(weight,value,index-1,capacity);
    return max(include,exclude);
}

int knapsackByMem(vector<int> weight, vector<int> value, int index, int capacity, vector<vector<int>> &dp) {
	// Write your code here
    if(index == 0){
        if(capacity>= weight[index]){
            return value[index];
        }else{
            return 0;
        }
    }
    if(dp[index][capacity] != -1) {
        return dp[index][capacity];
    }
    int include = INT_MIN;
    if(weight[index] <= capacity){
        include = value[index] + knapsackByMem(weight,value,index-1,capacity-weight[index],dp);
    }
    int exclude = knapsackByMem(weight,value,index-1,capacity,dp);
    dp[index][capacity] = max(include,exclude);
    return dp[index][capacity];
}

int knapsackByTab(vector<int> weight, vector<int> value, int index, int capacity) {
	// Write your code here
    vector<vector<int>> dp(index+1, vector<int> (capacity+1,0));
    if(index == 0){
        if(capacity>= weight[index]){
            return value[index];
        }else{
            return 0;
        }
    }
    dp[0][capacity] = value[0];
    for(int i =1 ; i<=index;i++){
        int include = INT_MIN;
        if(weight[i] <= capacity){
            include = value[i]+dp[i-1][capacity];
            capacity = capacity- weight[i];
        }
        int exclude = knapsackByMem(weight,value,index-1,capacity,dp);
        dp[index][capacity] = max(include,exclude);

    }
    return dp[index][capacity];
}



int knapsack(vector<int> weight, vector<int> value, int n, int capacity) {
	// Write your code here
    // int ans = knapsackByRec(weight,value,n-1,capacity);

    // vector<vector<int>> dp(n, vector<int>(capacity+1,-1));
    // int ans = knapsackByMem(weight,value,n-1,capacity,dp);


    int ans = knapsackByTab(weight,value,n-1,capacity);
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,maxWeight;
        cin >> n;
        vector<int> weight(n,0);
        vector<int> value(n,0);
        for(int i=0;i<n;i++){
            cin>>weight[i];
        }
        for(int i=0;i<n;i++){
            cin>>value[i];
        }
        cin>>maxWeight;
        cout<<knapsack(weight,value,n,maxWeight);
    }
}