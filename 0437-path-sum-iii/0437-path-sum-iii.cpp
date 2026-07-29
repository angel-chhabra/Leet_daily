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
unordered_map<long long, int> map;
int solve(TreeNode* root , int targetSum , long long currSum){
    if(root==nullptr){
        return 0;
    }
    currSum+=root->val;
    int count=0;
    if(map.count(currSum-targetSum)){  //agr map m vo prefix h to , count m add krdo jitni bar bhi vo number map m present h.
        count+=map[currSum-targetSum];
    }
    map[currSum]++;  //agr uska prefix present nhi h to b usko to map m add krna hi h
    count+=solve(root->left , targetSum , currSum);  //left nd right subtree se jo b valid paths niklnge vo bhi count m add honge along w the curr node's valid paths!
    count+=solve(root->right , targetSum , currSum);
    map[currSum]--; //backtracking , jb vo paths count m add hojaynge to unhe niklna b to pdega map se
    return count;
}
    int pathSum(TreeNode* root, int targetSum) {
        map[0]=1;  //start m 0 currsum se start krnge jiski freq 1 h.
      return solve(root , targetSum , 0);
        
    }
};