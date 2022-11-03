#include<bits/stdc++.h>
using namespace std;

int cut(int n, int x, int y, int z){
    if(n==0) {
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    int xCut = cut(n-x, x,y,z)+1;
    int yCut = cut(n-y, x,y,z)+1;
    int zCut = cut(n-z, x,y,z)+1;
    return max(xCut,max(yCut,zCut));

}

int cutByMem(int n, int x, int y, int z, vector<int> &dp){
    if(n==0) {
        dp[n] = 0;
        return dp[n];
    }
    if(n<0){
        return INT_MIN;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int xCut = cutByMem(n-x, x,y,z,dp)+1;
    int yCut = cutByMem(n-y, x,y,z,dp)+1;
    int zCut = cutByMem(n-z, x,y,z,dp)+1;
    dp[n] = max(xCut,max(yCut,zCut));
    return dp[n];

}

int cutByTab(int n, int x, int y, int z){
    vector<int> &dp(n+1,INT_MIN);
    dp[0] = 0;
    for(int i=1 ;i<=n ;i++){
        // if(i-x>=0){
        //     dp[i] = max()
        // }
        int xCut = dp[i-x]+1;
        int yCut = dp[i-y]+1;
        int zCut = dp[i-z]+1;
        dp[i] = max(xCut,max(yCut,zCut));
    }
    
    return dp[n];

}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
    vector<int> dp(n+1,-1);
    // int ans = cut(n,x,y,z);


    // int ans = cutByMem(n,x,y,z, dp);

    int ans = cutByTab(n,x,y,z);


    if(ans < 0){
        return 0;
    }
    return ans;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y,z;
        cin>>n;
        cin>>x;
        cin>>y;
        cin>>z;
        cout<<endl<<cutSegments(n,x,y,z)<<endl;
    }
}