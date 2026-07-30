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
vector<int> ans;
void inorder(TreeNode* root){  //inorder of BST is a sorted vector
    if(root==nullptr) return;
    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
}
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int mini=INT_MAX;
        int diff=0;
        for(int i=1;i<ans.size();i++){ 
            diff=ans[i]-ans[i-1];  //inside the sorted vector , calculating diff
            mini=min(mini , diff);
        }
        return mini;
    }
};