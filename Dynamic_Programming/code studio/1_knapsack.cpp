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

int knapsackByTab(vector<int> weight, vector<int> value, int n, int capacity) {
	// Write your code here
    vector<vector<int>> dp(n, vector<int> (capacity+1,0));
    for(int w=0; w<=capacity; w++){
        if(weight[0] <= capacity ){
            dp[0][w] = value[0];
        }else{
            dp[0][w] = 0;
        }
        cout<<dp[0][w]<<" ";
    }
    cout<<endl;
    for(int i =1 ; i<n;i++){
        for(int w= 0; w<=capacity;w++){
            int include = INT_MIN;
            if(weight[i] <= w){
                include = value[i]+dp[i-1][w-weight[i]];
            }
            int exclude = 0+dp[i-1][w];
            dp[i][w] = max(include,exclude);
            cout<<dp[i][w]<<" ";
        }
        cout<<endl;

    }
    return dp[n-1][capacity];
}

int knapsackByTabSc(vector<int> weight, vector<int> value, int n, int capacity) {
	// Write your code here
    vector<vector<int>> dp(n, vector<int> (capacity+1,0));
    for(int w=0; w<=capacity; w++){
        if(weight[0] <= capacity ){
            dp[0][w] = value[0];
        }else{
            dp[0][w] = 0;
        }
    }
    for(int i =1 ; i<n;i++){
        for(int w= 0; w<=capacity;w++){
            int include = INT_MIN;
            if(weight[i] <= w){
                include = value[i]+dp[i-1][w-weight[i]];
            }
            int exclude = 0+dp[i-1][w];
            dp[i][w] = max(include,exclude);
        }

    }
    return dp[n-1][capacity];
}



int knapsack(vector<int> weight, vector<int> value, int n, int capacity) {
	// Write your code here
    // int ans = knapsackByRec(weight,value,n-1,capacity);

    // vector<vector<int>> dp(n, vector<int>(capacity+1,-1));
    // int ans = knapsackByMem(weight,value,n-1,capacity,dp);


    int ans = knapsackByTab(weight,value,n,capacity);
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