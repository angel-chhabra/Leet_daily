class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>res (m*n , 0);
        int i=0 , j=0;
        for(int idx=0;idx<m*n;idx++){
            res[idx]=mat[i][j];   //jab b upr jare h even sum h nd niche are h to odd ara h 
            if((i+j)%2==0){    //even
              if(j==n-1) i++;
              else if(i==0) j++;
              else{
                i--;
                j++;
              }
            } else{    //odd
                if(i==m-1) j++;
                else if(j==0) i++;
                else{
                    i++;
                    j--;
                }
            }

        }
        return res;
        
    }
};