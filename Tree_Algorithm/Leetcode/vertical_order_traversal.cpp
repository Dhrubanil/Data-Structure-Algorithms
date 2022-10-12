#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void CreateTreeFromLevelOrder(TreeNode* &root,vector<int> &v){
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        cout<<"root->"<<root->val<<endl;
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(v[i]!= -1){
                cout<<"l->"<<v[i]<<endl;
                temp->left = new TreeNode(v[i]);
                q.push(temp->left);
            }
            i++;
            if(v[i]!= -1){
                cout<<"r->"<<v[i]<<endl;
                temp->right = new TreeNode(v[i]);
                q.push(temp->right);
            }
            i++;
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root== nullptr){
            return {{}};
        }
        map<int,map<int,vector<int>>>nodes; // for storing hd and levl wise nodes 
        queue<pair<TreeNode*,pair<int,int>>> q;  // queue for pair(nodes, pair(horiz dist,level))
        q.push(make_pair(root,make_pair(0,0)));
        vector<vector<int>> ans;
        while(!q.empty()){

            pair<TreeNode*,pair<int,int>> temp = q.front(); 
            q.pop();

            TreeNode *firstnode = temp.first;
            int level =  temp.second.first;
            int hd = temp.second.second;

            nodes[hd][level].push_back(firstnode->val);
            sort(nodes[hd][level].begin(),nodes[hd][level].end());

            if(firstnode->left !=nullptr){
                TreeNode *left = firstnode->left;
                pair<int,int> distLvl = make_pair(level+1,hd-1);
                q.push(make_pair(left,distLvl));
            }

            if(firstnode->right !=nullptr){
                TreeNode *right = firstnode->right;
                pair<int,int> distLvl = make_pair(level+1,hd+1);
                q.push(make_pair(right,distLvl));
            }
        }
        
        map<int,vector<int>> m1;
        
        for(auto i:nodes){
            for(auto j : i.second){
                for(auto k: j.second){
                    m1[i.first].push_back(k);
                }
            }
        }
        for(auto i: m1){
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main(){
    vector<int> v{1,2,3,4,6,5,7,-1,-1,-1,-1,-1,-1,-1,-1};
    TreeNode *root = new TreeNode(v[0]);
    Solution *s = new Solution();
    s->CreateTreeFromLevelOrder(root,v);
    vector<vector<int>> res = s->verticalTraversal(root);
    cout<<"[";
    for(int i = 0; i<res.size();i++){
        cout<<"[";
        for(int j = 0; j<res[i].size();j++){
            cout<<res[i][j];
            if(j!=res[i].size()-1){
                cout<<",";
            }
        }
        cout<<"]";
    }
    cout<<']'<<endl;
}