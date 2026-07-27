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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return false;
        }
        if(root->left==nullptr && root->right==nullptr){  //agr children h hi n then compare w root only
            return targetSum==root->val;
        }
        bool a=hasPathSum(root->left , targetSum-root->val);  //left subtree and root ki val minus kro target m se , minus krte krte check krlnge jis path p target 0 hojega fr
        bool b=hasPathSum(root->right , targetSum-root->val);
        return a || b; //right or left m se koi b subtree ka path true ho to ans true

    }
};