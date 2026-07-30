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
vector<TreeNode*> nums;
void inorder(TreeNode* root){
    if(root==nullptr) return;
    inorder(root->left);
    nums.push_back(root);    //node store krnge in sorted order
    inorder(root->right);
}
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        TreeNode* temp=new TreeNode(-1);  //temp node bnai w value -1.
        TreeNode* curr=temp;  //usko point kr ke rkha taki next se apna main tree bnaye
        for(auto node: nums){
            node->left=NULL;  //left m kch n hona chiye
            temp->right=node; //right m node dalte jao and agla agla right chlte jao
            temp=temp->right;
        }
        return curr->right; //main tree jo bnaya h uska node return krna pdega
        
    }
};