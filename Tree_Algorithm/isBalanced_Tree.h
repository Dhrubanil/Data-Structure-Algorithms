#include<bits/stdc++.h>
#include "node.h"

// class node{
//     public:
//         int data;
//         node *left;
//         node *right;
//         node(int data){
//             this->data=data;
//             this->left=NULL;
//             this->right=NULL;
//         }
// };

int height(node* node) 
{ 
    if (node == NULL) 
        return 0; 
    int lheight = height(node->left); 
    int rheight = height(node->right); 
    return max(lheight,rheight)+1;
    
} 

bool isBalanced(node *root){
    // a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

    //Base Case

    // -------First Way
    if(root==NULL){
        return true;
    }
    int leftBalance = isBalanced(root->left);
    int rightBalance = isBalanced(root->right);
    int heightOfLeftSubTree = height(root->left);
    int heightOfRightSubTree = height(root->right);
    int diff = abs(heightOfLeftSubTree-heightOfRightSubTree);
    return (diff<=1 && leftBalance && rightBalance);
}