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
int maxi=0;  //gloabl maximum bnaya for evry node , kyuki diameter can include both left and right , hr node pr ja ja kr check krnge or maxi m store krynge last me most max wala return hojega
int height(TreeNode* root){
    if(root==NULL) return 0;
    int left=height(root->left);
    int right=height(root->right);
    maxi=max(maxi , left+right);   //for max diameter
    return max(left , right)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxi;
        
    }
};