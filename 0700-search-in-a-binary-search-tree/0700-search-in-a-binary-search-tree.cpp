/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
         if(root==nullptr){
            return root;
        }
        if(root->val==val){  //agr root p hi value miljae to return root 
            return root;
        }
        TreeNode* left=searchBST(root->left , val);  //for left subtree
        TreeNode* right=searchBST(root->right , val); //for right subtree
        return left!=NULL? left:right;  //agr leftsubtree h hi nhi , to right m hi jana h
    } 
};