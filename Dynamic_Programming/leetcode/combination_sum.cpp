#include <bits/stdc++.h>
using namespace std;

void combination(vector<int>& candidates, int target, vector<int> ans, vector<vector<int>> &result){
    if(target == 0){
        result.push_back(ans);
        return;
    }
    if(target < 0){
        return;
    }
    for(int i = 0; i<candidates.size() ; i++){
        ans.push_back(candidates[i]);
        combination( candidates, target-candidates[i], ans, result );
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // vector<int> dp();
    vector<int> ans;
    vector<vector<int>> result;
    if(candidates.size() == 0){
        return result;
    }
    int sum = 0;
    int start = 0;
    combination( candidates, target, ans, result);
    return result;
}

int main(){
    vector<int> candidates{2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = combinationSum( candidates, target );
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<"[ ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<",";
        }
        cout<<"] , ";
    }
    cout<<" ]"<<endl;
}