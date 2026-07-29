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
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*>q;  //SAME BFS APPROACH!!
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
        int sum=0;
        for(int i=0;i<ans.size();i++){  //ans ko traverse krnge
            if(i==ans.size()-1){  //jse hi last level pr phuche , usko traverse krnge
                for(auto j : ans[i]){  //uski sari values , sum m add krnge 
                    sum+=j;
                }
            }
        }
        return sum;
        
    }
};