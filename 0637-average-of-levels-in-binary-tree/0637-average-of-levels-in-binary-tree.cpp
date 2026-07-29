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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector<vector<double>> ans;
        if(root==nullptr){
            return result;
        }
        queue<TreeNode*> q;  //SAME DFS APPROACH!!
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<double> level;
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
        for(auto level:ans){  // last m ans(2d vec) ke hr level ko traverse krnge
            double avg=0;
            double sum=0;
            for(int j: level){  //hr level k hr element ko traverse krge
                sum+=j;  //and add krte jynge
            }
            avg=sum/level.size();  //hr level ka avg nikalnge
            result.push_back(avg);  //result m push krnge
        }
        return result;
        
    }
};