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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSum;
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*>q;  //first BFS to calculate n store the levelSum on each level
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                sum+=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            levelSum.push_back(sum);
        }
        root->val=0;   //first level to 0 hi hoga
        q.push(root);
        int level=0;
        while(!q.empty()){  //second BFS to calculate the childsum and overwrite , the existing tree with cousin values
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                int childsum=0;
                if(curr->left) childsum+=curr->left->val;
                if(curr->right) childsum+=curr->right->val;
                if(curr->left){
                    curr->left->val=levelSum[level+1]-childsum;  //cousin value is actually the levelsum of the next level - childsum of that prticular node
                    q.push(curr->left);   //uske bd q m push kro
                }
                if(curr->right){
                    curr->right->val=levelSum[level+1]-childsum;
                    q.push(curr->right);
                }
            }
            level++;   //each time level will be incrased
        }
        return root;
    }
};