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
    int minDepth(TreeNode* root) {
        if(root==nullptr){
             return 0;
        }
        int ans=0;
        int left=minDepth(root->left);  //left and right subtree ki height nikali
        int right=minDepth(root->right);
        if(root->left==nullptr) return right+1;  //agr left null to rightwale ki lelo and vice-versa
        if(root->right==nullptr) return left+1;
        ans=min(left , right)+1;
        return ans;
    }
};