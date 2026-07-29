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
vector<vector<int>> ans;
void solve(vector<int>temp , int currsum , int targetSum , TreeNode*root){
    if(root==NULL)return;
    temp.push_back(root->val);  //hr br temp m push krte jana h elemnts ko 
    currsum+=root->val;        //sum m b hr bar add krte jao hr nodeki value
    if(root->left==NULL && root->right==NULL){  //agr hm leaf node pr agye h to check krnge (as per ques root to leaf hona chahiye path)
        if(currsum==targetSum) ans.push_back(temp);
            
        }
        solve(temp , currsum , targetSum , root->left);
        solve(temp , currsum, targetSum , root->right);
}



    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        solve(temp , 0  , targetSum , root);
        return ans;
        
    }
};