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
int h(TreeNode* root) {  // height nikalne ka func seperately
    int ans=0;
        if(root==nullptr){
            return 0;
        }
        int left=h(root->left);  //left subtree ki h
        int right=h(root->right); //right subtree ki h
        ans=max(left , right)+1;  //dono m se jo bmax hogi vhi tree ki asli height hogi 
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        } 
        int a = h(root->left);   //left subtree ki height nikal li
        int b = h(root->right);  //right subtree ki height nikal li
        if((abs(a - b ))>1){  //comparision of balanced tree formula agr alg ara h so false
            return false;
        }else{
            return isBalanced(root->left) && isBalanced(root->right);  //otherwise , left m jao to check if it is balnaced or no n then right m jao

        }
         return false;
        
    }
};