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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        vector<vector<int>> ans;
        if(root==nullptr){
            return result;
        }
        queue<TreeNode*>q;  //DFS APPROACH!!
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ans.push_back(level);
        }
        for(auto level: ans){  //last m apne ans(2D matrix) ke hr level ko traverse krnge
            int maxi=INT_MIN;
            for(auto j: level){  //hr level ke hrr element ko traverse krnge and find the maximum one.
                maxi=max(maxi , j);
            }
            result.push_back(maxi);
        }
        return result;
    }
};