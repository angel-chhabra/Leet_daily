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
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return false;
        }
        queue<TreeNode*>q;  //SAME BFS PPROACH
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
            TreeNode*curr=q.front();
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
        int levelNo=0;
        for(auto level: ans){  //ans ke hr level m jaynge
        for(int i=0;i<level.size();i++){
            if(levelNo%2==0){ //even level  
                if(level[i]%2==0) return false;  //agr node hi even hogye to false
                    if(i>0 &&level[i]<=level[i-1]) return false;
                } else{  //odd level
                  if(level[i]%2==1) return false;  // agr node hi odd hogye to false
                    if( i>0 &&level[i]>=level[i-1]) return false;
            }
        }
             levelNo++;
        }
        return true;
    }
};