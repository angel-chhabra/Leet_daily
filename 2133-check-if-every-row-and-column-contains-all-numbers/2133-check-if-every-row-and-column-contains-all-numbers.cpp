class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            vector<bool>row(n+1 , false);
            vector<bool>col(n+1 , false);
            for(int j=0;j<n;j++){
                if(row[matrix[i][j]]){  //if dupliacte present 
                    return false;
                } else{
                    row[matrix[i][j]]=true; //pehle se vector m nhi tha to now add nd put true to it
                }
                if(col[matrix[j][i]]){
                    return false; 
                } else{
                    col[matrix[j][i]]=true;
                }

            }
        }
        return true;






        // unordered_set<int> s1 , s2;   //for not storing duplicates
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(s1.find(matrix[i][j])!=s1.end()){
        //             return false;
        //         } else{
        //             s1.insert(matrix[i][j]);
        //         } 
        //          if(s2.find(matrix[j][i])!=s2.end()){
        //             return false;
        //         } else{
        //             s2.insert(matrix[j][i]);
        //         }
        //     }
        //     s1.clear();  //important as we need to clear up the set 
        //     s2.clear();
        // }

        //return true;
        
    }
};