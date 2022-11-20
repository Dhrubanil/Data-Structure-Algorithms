#include<bits/stdc++.h>
using namespace std;

int minCostByRec(vector<int>& days, vector<int>& costs, int index){
    if(index >= days.size()){
        return 0;
    }
    // 1 Day pass & cost
    int opt1 = costs[0] + minCostByRec(days,costs,index+1);

    // 7 Day pass & cost
    int i;
    for( i=index; i<days.size() && days[i] < days[index]+7 ; i++ );
    int opt2 = costs[1] + minCostByRec(days,costs,i);

    // 30 Day pass & cost
    for( i=index; i<days.size() && days[i] < days[index]+30 ; i++ );
    int opt3 = costs[2] + minCostByRec(days,costs,i);

    int ans = min(opt1,min(opt2,opt3));
    return ans;
}

int minCostByMem(vector<int>& days, vector<int>& costs, int index, vector<int> &dp){
    if(index >= days.size()){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }
    // 1 Day pass & cost
    int opt1 = costs[0] + minCostByMem(days,costs,index+1,dp);

    // 7 Day pass & cost
    int i;
    for( i=index; i<days.size() && days[i] < days[index]+7 ; i++ );
    int opt2 = costs[1] + minCostByMem(days,costs,i,dp);

    // 30 Day pass & cost
    for( i=index; i<days.size() && days[i] < days[index]+30 ; i++ );
    int opt3 = costs[2] + minCostByMem(days,costs,i,dp);

    dp[index] = min(opt1,min(opt2,opt3));
    return dp[index];
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int index = 0;

    vector<int> dp(days.size()+1,-1);

    // int ans = minCostByRec(days,costs,index);

    int ans = minCostByMem(days,costs,index,dp);

    return ans;
}

int main(){
    vector<int> days{1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs{2,7,15};
    cout<<mincostTickets(days,costs)<<endl;
}