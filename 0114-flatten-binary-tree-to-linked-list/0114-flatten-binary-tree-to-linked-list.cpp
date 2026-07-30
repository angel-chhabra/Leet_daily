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
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr!=nullptr){
            if(curr->left){  //left subtree m jynge
                TreeNode*temp=curr->left;
                while(temp->right)  //sbse right m jana h hme left subtree ke
                    temp=temp->right;
                    temp->right=curr->right;  //sbse right m jakr vha main root ka right subtree attach krdo
    
                curr->right=curr->left; //ab jo sb kia h left m vo sb main root ke right m lgado
                curr->left=nullptr;  //and left ko null krdo
            }
            curr=curr->right;
    }
    }
};