class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> rowmini;
        vector<int>colmaxi;
        for(int i=0;i<n;i++){    //sari rows m jaynge and find the min
            int mini=INT_MAX;
            for(int j=0;j<m;j++){
               mini = min(mini , matrix[i][j]);
            }
            rowmini.push_back(mini);
        }

        for(int i=0;i<m;i++){   //sare cols m jaynge and find the max 
            int maxi=INT_MIN;
            for(int j=0;j<n;j++){
                maxi = max(maxi , matrix[j][i]);
            }
            colmaxi.push_back(maxi);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<matrix[i].size();j++){   //agr current element dono condition satisfy krta h to it is the ans!
                if(matrix[i][j]==rowmini[i]  && matrix[i][j]==colmaxi[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;  //optimization is still possible-> sari rows ke min m se 1 max value nikalo and sare cols ke max m se 1 min value nikalo if they r equal then it is ur ans 
    }
};