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
void swap(TreeNode* l , TreeNode* r , int level){
    if(l==NULL || r==NULL){
        return;
    }
    if(level%2==1){
    int temp=l->val;  //swapping krdi node ki values ki
    l->val=r->val;
    r->val=temp;
    }

    swap(l->left , r->right , level+1);  //ab l ke b left m jjynge nd r ke right  m
    swap(l->right , r->left , level+1);  //ab l k right  and r ke left m 

}
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL) return root;
        swap(root->left , root->right , 1);
        return root;
    }
};