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
void dfs(TreeNode*root , int level , vector<vector<int>>&ans){  //DFS APPROACH!!
    if(root==nullptr){
        return;
    }
    if(level==ans.size()){  //means agr level b 0 h and abi ans ka size b 0 h , to khali space denge ans m taki agli node ki val insert ho ske
        ans.push_back({});
    }
    ans[level].push_back(root->val);  //hr level k lie ans m value jaygi
    dfs(root->left , level+1 , ans);
    dfs(root->right , level+1 , ans);
}



    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root , 0 , ans);
        return ans;
    }
};