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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*>q;  //BFS APPRoach
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n=q.size();
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
        for(int i=0;i<ans.size();i++){   //level order nikal kr , bs last m odd wale ko even wale se revrse krdia bs
                 if(i%2==1){
                reverse(ans[i].begin() , ans[i].end());
            }
        }
        return ans;
    }
};