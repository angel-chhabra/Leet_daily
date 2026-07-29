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
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*> q;  // SAME BFS APPROACH!!
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ans.push_back(level);
        }

        int maxi=INT_MIN;  
        int anslevel=0;  // JO ANS M LEVEL RETURN KRNA H
        int levelNo=1;   //JIS CURR LEVEL PR HM CHLRE H
        for(auto level:ans){
            int sum=0;
            for(auto j: level){
                sum+=j;
            }
            if(sum>maxi){   
                maxi=sum;   //MAXI M MAX SUM STORE HOJAYEGA 
                anslevel=levelNo;  // AND ABHI KE ACCORDING , ANS LEVEL IS THIS CURR LEVEL AS IT HAS MAX SUM.
            }
            levelNo++;  //AGLE LEVEL PR CHLNGE TAKI SB LEVEL KE SU COMPARE KR SKE
        }
        return anslevel;
        
    }
};