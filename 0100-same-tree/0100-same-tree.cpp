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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;  //agr dono null means exact same
        if(p==nullptr || q==nullptr) return false;  //agr ek null means bilkul same nhi hoskte
        if(p->val==q->val){  //if nodes are equal then we'll go for right and left subtrees
        bool left=isSameTree(p->left , q->left);
        bool right=isSameTree(p->right ,  q->right);
        return left&&right;  //to compare if left's ans is same as right's ans!
    } 
    return false;
    }
};