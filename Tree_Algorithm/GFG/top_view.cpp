#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node() : data(0), left(NULL), right(NULL) {}
    Node(int x) : data(x), left(NULL), right(NULL) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void CreateTreeFromLevelOrder(Node* &root,vector<int> &v){
        queue<Node*> q;
        q.push(root);
        int i=1;
        while(!q.empty()){
            Node *temp = q.front();
            q.pop();
            if(v[i]!= -1){
                cout<<"l->"<<v[i]<<endl;
                temp->left = new Node(v[i]);
                q.push(temp->left);
            }
            i++;
            if(v[i]!= -1){
                temp->right = new Node(v[i]);
                q.push(temp->right);
            }
            i++;
        }
    }
    
    void leftTop(Node *root, vector<int> &v){
        if(root==NULL){
            return;
        }
        leftTop(root->left,v);
        v.push_back(root->data);
    }

    void rightTop(Node *root, vector<int> &v){
        if(root==NULL){
            return;
        }
        v.push_back(root->data);
        rightTop(root->right,v);
    }

    vector<int> topView(Node *root)
    {
        //Your code here
        if(root == NULL)return {};
        vector<int> v;
        leftTop(root->left,v);
        v.push_back(root->data);
        rightTop(root->right,v);
        return v;
    }

};

int main(){
    vector<int> v{1,2,3,4,6,5,7,-1,-1,-1,-1,-1,-1,-1,-1};
    Node *root = new Node(v[0]);
    Solution *s = new Solution();
    s->CreateTreeFromLevelOrder(root,v);
    vector<int> ans = s->topView(root);
    for(int i=0 ; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}