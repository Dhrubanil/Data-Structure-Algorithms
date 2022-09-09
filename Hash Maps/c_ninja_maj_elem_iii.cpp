#include<bits/stdc++.h>
using namespace std;

vector<int> countTheNumber(vector<int> &arr, int n, int k) {
	// Write your code here.
    map <int,int> mapping;
    vector<int> res;
    for(int i=0;i<n;i++){
        mapping[arr[i]]++;
    }
    for(auto it:mapping){
        if(it.second>=(n/k)){
            res.push_back(it.first);
        }
    }
    return res;
}

int main(){
    vector<int>v{1,2,3,3,3,3,4,4,4,1,2,0};
    vector<int> res = countTheNumber(v,v.size(),4);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }cout<<endl;
}