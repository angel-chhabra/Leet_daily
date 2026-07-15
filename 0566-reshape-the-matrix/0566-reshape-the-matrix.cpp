class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       int m=mat.size();
       int n=mat[0].size();
       if(m*n != r*c){  //agr size equal nhi h to reshape kse hi hogi , bde se chote m ya chote se bde m not possible
        return mat;
       }
       vector<vector<int>> ans(r , vector<int>(c));
       for(int i=0;i<m*n;i++){
        ans[i/c][i%c]=mat[i/n][i%n];  //converting these 1d pointers in 2d form for 2d matrix!
       }
       return ans;
    }
};