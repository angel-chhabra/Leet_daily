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
vector<int>ans;
void inorder(TreeNode* root){
    if(root==nullptr) return;  //inorder se sorted order m array bnjayega(BST PROPERTY)
    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
}


    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root);
        int sum=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]>=low && ans[i]<=high){  //arr m traverse kr ke condition check krte jynge
                sum+=ans[i];
            }
        }
        return sum; 
    }
};