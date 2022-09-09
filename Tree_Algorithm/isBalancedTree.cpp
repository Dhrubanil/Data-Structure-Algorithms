#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;
        node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

int height(node* node) 
{ 
    if (node == NULL) 
        return 0; 
    int lheight = height(node->left); 
    int rheight = height(node->right); 
    return max(lheight,rheight)+1;
    
} 

node *CreateTree(node *root){
    cout<<"Enter the value : "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter the left child of "<<root->data<<" : "<<endl;
    root->left= CreateTree(root->left);
    cout<<"Enter the right child of "<<root->data<<" : "<<endl;
    root->right = CreateTree(root->right);
    return root;
}

bool isBalancedFirstWay( node *root){
    // a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

    //Base Case

    //< -------First Way ----------->
    if(root==NULL){
        return true;
    }
    int leftBalance = isBalancedFirstWay(root->left);
    int rightBalance = isBalancedFirstWay(root->right);
    int heightOfLeftSubTree = height(root->left);
    int heightOfRightSubTree = height(root->right);
    int diff = abs(heightOfLeftSubTree-heightOfRightSubTree);
    return (diff<=1 && leftBalance && rightBalance);

}

pair<bool,int> balance(node *root){
    if(!root){
        return make_pair(true,0);
    }
    pair<bool,int> leftBalance = balance(root->left);
    pair<bool,int> rightBalance = balance(root->right);
    bool isBalanceLeftSubTree = leftBalance.first;
    bool isBalanceRightSubTree = rightBalance.first;
    int diffOfHeight = abs(leftBalance.second - rightBalance.second);
    int height = max(leftBalance.second,rightBalance.second)+1;

    pair<bool,int> ans;

    ans.first = (diffOfHeight<=1 && isBalanceLeftSubTree && isBalanceRightSubTree);
    ans.second = height;

    return ans;
}
bool isBalancedBestWay( node *root){
    // a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
    return balance(root).first;
}

int main(){

}