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
    int maxDepth(TreeNode* root) {
        int ans=0;
        if(root==nullptr){
            return 0;
        }
        int left=maxDepth(root->left);  //left subtree ki h
        int right=maxDepth(root->right); //right subtree ki h
        ans=max(left , right)+1;  //+1 krna pdega kyuki ek level chota ara(root ko b to add krna h)
        return ans;
    }
};