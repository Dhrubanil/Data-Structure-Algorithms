#include<bits/stdc++.h>
using namespace std;

void createSubset(vector<int> &v, vector<int> output, vector<vector<int>> &ans ,int start){
    if(start>=v.size()){
        ans.push_back(output);
        return;
    }
    //exclude

    createSubset(v,output,ans,start+1);

    //include

    output.push_back(v[start]);
    createSubset(v,output,ans,start+1);
}

vector<vector<int>> subset(vector<int> &v){
    vector<vector<int>> ans;
    vector<int> output;
    int start = 0;
    createSubset(v,output,ans,start);
    return ans;
}

int main(){
    vector<int> v{1,2,3};
    vector<vector<int>> ans=subset(v);
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
