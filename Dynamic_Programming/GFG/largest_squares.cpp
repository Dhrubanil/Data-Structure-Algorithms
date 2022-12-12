#include <bits/stdc++.h>
using namespace std;

int solveByRec(vector<vector<int>> mat, int i,int j, int &maxi ){

    if(i>=mat.size() || j>= mat[0].size()){
        return 0;
    }

    int right = solveByRec(mat, i,j+1,maxi);
    int diagonal = solveByRec(mat,i+1,j+1,maxi);
    int left = solveByRec(mat,i+1,j, maxi);
    if(mat[i][j] == 1){
        int ans =  1+min(right,min(left,diagonal));
        maxi = max(maxi,ans);
        return ans;
    }else{
        return 0;
    }

}

int solvebyMem(vector<vector<int>> &mat, int i,int j, int &maxi, vector<vector<int>> &dp ){

    if(i>=mat.size() || j>= mat[0].size()){
        return 0;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int right = solvebyMem(mat, i,j+1,maxi, dp);
    int diagonal = solvebyMem(mat,i+1,j+1,maxi, dp);
    int left = solvebyMem(mat,i+1,j, maxi, dp);
    cout<<i<<j<<endl;
    
    if(mat[i][j] == 1){
        dp[i][j] =  1+min(right,min(left,diagonal));
        maxi = max(maxi,dp[i][j]);
        return dp[i][j];
    }else{
        dp[i][j] = 0;
        return dp[i][j];
    }

}


void solvebyTab(vector<vector<int>> &mat, int &maxi){
    int n= mat.size();
    int m= mat[0].size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int down = dp[i+1][j];
            if(mat[i][j] == 1){
                dp[i][j] = 1+min(right,min(diagonal,down));
                maxi = max(maxi,dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }

    }

}


void solvebyTabSc(vector<vector<int>> &mat, int &maxi){
    int n= mat.size();
    int m= mat[0].size();
    vector<int> curr(m+1,0);
    vector<int> next(m+1,0);
    // vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int right = curr[j+1];
            int diagonal = next[j+1];
            int down = next[j];
            if(mat[i][j] == 1){
                curr[j] = 1+min(right,min(diagonal,down));
                maxi = max(maxi,curr[j]);
            }else{
                curr[j] = 0;
            }
        }
        next = curr;

    }

}


int maxSquare(int n, int m, vector<vector<int>> mat){
    // code here
    int maxi = 0;
    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
    // int ans = solveByRec(mat,0,0, maxi);
    // int ans = solvebyMem(mat,0,0, maxi, dp);

    // solvebyTab(mat, maxi);
    solvebyTabSc(mat, maxi);
    return maxi;
}

int main(){
    vector<vector<int>> mat{{1, 1},{1, 1}};
    cout<<maxSquare(mat.size(),mat[0].size(),mat)<<endl;
}