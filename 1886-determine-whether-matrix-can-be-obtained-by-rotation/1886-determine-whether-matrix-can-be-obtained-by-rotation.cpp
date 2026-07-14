class Solution {
public:
    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
        int m=matrix.size();
        vector<bool> ans(4, true);   //constatnt space 4 ka hi vector h , so np to SC.
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=target[j][m-i-1]){   //90deg
                    ans[0]= false;
                } 
                if(matrix[i][j]!=target[m-i-1][m-j-1]){  //180deg
                    ans[1]=false;
                }  
                if(matrix[i][j]!=target[m-j-1][i]){    //270deg
                    ans[2]=false;
                } 
                if (matrix[i][j]!=target[i][j]){    //360deg
                    ans[3]=false;
                }
            }
        }
        return ans[0] || ans[1] || ans[2] || ans[3];
        
    }
};