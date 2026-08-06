class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1]){ //taking out common of the 1st 2 edges
            return edges[0][0];
        } 
        return edges[0][1];
    }
};