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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==nullptr){
            return root;
        }
        if(depth==1){
            TreeNode* newroot=new TreeNode(val);  //agr depth hi 1 hogyi , to val root ke upr lgegi as a new node.
            newroot->left=root;
            return newroot;
        }
        int levelNo=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>level;
            for(int i=0;i<n;i++){
                TreeNode*curr=q.front();
                q.pop();
                level.push_back(curr->val);
                if(levelNo==depth-1){
                    TreeNode* oldleft=curr->left;  //purani nodes ko store krao
                    TreeNode* oldright=curr->right;
                    curr->left= new TreeNode(val);  //new nodes lgao 
                    curr->right= new TreeNode(val);
                    curr->left->left=oldleft; //newnodes ke left n right m wps purani ko jodo
                    curr->right->right=oldright;
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            levelNo++;
        }
        return root;
        
    }
};