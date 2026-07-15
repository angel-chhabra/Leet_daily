class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m , vector<int>(n));
        int k=original.size();
        if(k!=m*n){  //agr size equal nhi to we cant fit 
            return {};
        }
        for(int i=0;i<m*n;i++){
            ans[i/n][i%n]=original[i];   // converting 2d indices into flat array form

        }
        return ans;
        
    }
};