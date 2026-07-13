class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        int row=n-1;      //staircase problem!!
        int col=0;
        while(row>=0  && col<m ){    //sbse niche wale row ka 0th col element lenge
                if(grid[row][col]>=0){    //agr +ve milgya to mtlb aage bdho age milnge -ve
                    col++;   
                } else {
                    count+=m-col;     //agr -ve mila to pta hi h aage k sare -ve hi hoge so total col size-j(curr col)
                    row--;
                }
        }
            return count;
        
    }
};