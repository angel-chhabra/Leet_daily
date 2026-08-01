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
TreeNode* findmin(TreeNode*root){
    while(root->left){
        root=root->left;
    }
    return root;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return NULL;
        if(root->val>key){
            root->left=deleteNode(root->left , key);
        } else if(root->val<key){
            root->right=deleteNode(root->right , key);
        } else{
            if(!root->left){   //if no left child
                TreeNode*temp=root->right;
                delete root;
                return temp;
            }
            if(!root->right){  //if no right child
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
    //to remove node w 2 children , replace it with inorder sucessor(smallest in rightsubtree) or replace w inordere predecessor(largest in leftsubtree)!
            TreeNode*sucessor=findmin(root->right);
            root->val=sucessor->val;
            root->right=deleteNode(root->right , sucessor->val);
        }
        return root;
        
    }
};