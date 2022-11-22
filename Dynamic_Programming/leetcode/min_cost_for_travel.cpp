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

int minCostByTab(vector<int>& days, vector<int>& costs){
    int n = days.size();
    vector<int> dp(n+1,INT_MAX);

    dp[n] = 0;

    for(int index=n-1;index>=0;index--){
        // 1 Day pass & cost
        int opt1 = costs[0] + dp[index+1];

        // 7 Day pass & cost
        int i;
        for( i=index; i<n && days[i] < days[index]+7 ; i++ );
        int opt2 = costs[1] + dp[i];

        // 30 Day pass & cost
        for( i=index; i<n && days[i] < days[index]+30 ; i++ );
        int opt3 = costs[2] + dp[i];

        int ans = min(opt1,min(opt2,opt3));

        dp[index] = ans;
    }
    return dp[0];
}

int minCostBySc(vector<int>& days, vector<int>& costs){
    queue<pair<int,int>> monthly;
    queue<pair<int,int>> weekly;
    int ans = 0;

    for(int day:days){
        while(!weekly.empty() && weekly.front().first+7<=day){
            weekly.pop();
        }
        while(!monthly.empty() && monthly.front().first+30<=day){
            monthly.pop();
        }
        weekly.push(make_pair(day,costs[1]+ans));
        monthly.push(make_pair(day,costs[2]+ans));
        ans = min((ans+costs[0]), min(weekly.front().second,monthly.front().second));
    }
    return ans;
}
int mincostTickets(vector<int>& days, vector<int>& costs) {
    int index = 0;

    vector<int> dp(days.size()+1,-1);

    // int ans = minCostByRec(days,costs,index);

    // int ans = minCostByMem(days,costs,index,dp);

    // int ans = minCostByTab(days,costs);

    int ans = minCostBySc(days,costs);

    return ans;
}

int main(){
    // vector<int> days{2,5};
    // vector<int> costs{2,7,15};
    vector<int> days{1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs{2,7,15};
    cout<<mincostTickets(days,costs)<<endl;
}