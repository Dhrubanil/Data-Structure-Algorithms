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


void CreateTreeFromLevelOrder(node* &root,vector<int> &v){
    queue<node*> q;
    q.push(root);
    int i=1;
    cout<<"root->"<<root->data<<endl;
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        if(v[i]!= -1){
            cout<<"l->"<<v[i]<<endl;
            temp->left = new node(v[i]);
            q.push(temp->left);
        }
        i++;
        if(v[i]!= -1){
            cout<<"r->"<<v[i]<<endl;
            temp->right = new node(v[i]);
            q.push(temp->right);
        }
        i++;
    }
}
int height(node* node) 
{ 
    if (node == NULL) 
        return 0; 
    int lheight = height(node->left); 
    int rheight = height(node->right); 
    return max(lheight,rheight)+1;
    
} 

pair<int,int> longestPathBwTwoNodes(node* root){  //pair of (diameter,height) for making it o(n) time complexity
    // Base case
    if(!root){
        return make_pair(0,0);
    }
    pair<int,int> left = longestPathBwTwoNodes(root->left);
    pair<int,int> right = longestPathBwTwoNodes(root->right);

    int leftDiameter = left.first;
    int rightDiameter = right.first;
    int mixOfDiameter = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(leftDiameter,max(rightDiameter,mixOfDiameter));
    ans.second = max(left.second,right.second)+1;

    return ans;
}


int diameterOfTree(node *root){
    return longestPathBwTwoNodes(root).first;
}
  



void reverseLevelorderTraversalUsingStack(node *root){
    if(!root){
        return;
    }
    queue<node *>q;
    q.push(NULL);
    q.push(root);
    stack<node *> st;
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        st.push(temp);
        if(!temp){
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            if(temp->left){
                q.push(temp->left);
                // cout<<temp->left->data<<" ";
            }
            if(temp->right){
                q.push(temp->right);
                // cout<<temp->right->data<<" ";
            }
        }
    }
    while(!st.empty()){
        if(!st.top()){
            cout<<endl;
        }else{
        cout<<st.top()->data<<" ";
        }
        st.pop();
        // cout<<st.top()->data<<" ";
        // st.pop();
    }
        
}

void levelorderTraversal(node *root){
    if(!root){
        return;
    }
    queue<node *>q;
    q.push(root);
    q.push(NULL);
    cout<<endl;
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        if(!temp){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
                // cout<<temp->left->data<<" ";
            }
            if(temp->right){
                q.push(temp->right);
                // cout<<temp->right->data<<" ";
            }
        }
    }
}

void inOrderTraversal(node *root){
    if(!root){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(node *root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    // cout<<root->data<<" ";
}

void postOrderTraversal(node *root){
    if(!root){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}



int main(){
    node *root=NULL;
    root = CreateTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // cout<<"Level Order Traversal :";
    // levelorderTraversal(root);
    // cout<<endl;

    // cout<<"Reverse Level Order Traversal :";
    // reverseLevelorderTraversalUsingStack(root);
    // cout<<endl;

    // cout<<"In Order Traversal :";
    // inOrderTraversal(root);
    // cout<<endl;
    // cout<<endl;

    // cout<<"Pre Order Traversal :";
    // preOrderTraversal(root);
    // cout<<endl;
    // cout<<endl;

    // cout<<"Post Order Traversal :";
    // postOrderTraversal(root);
    // cout<<endl;
    // cout<<endl;
    
    // vector<int> levelOrderTreeInput{1,8,5,-1,11,17,-1,-1,-1,-1,-1,-1,-1};
    // node *root = new node(levelOrderTreeInput[0]);
    // CreateTreeFromLevelOrder(root,levelOrderTreeInput);
    // cout<<endl;
    // levelorderTraversal(root);
    // cout<<endl;
    // cout<< height(root);
    cout<<diameterOfTree(root);
}