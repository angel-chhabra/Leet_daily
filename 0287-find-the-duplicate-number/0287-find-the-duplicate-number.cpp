class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        unordered_map<int,int>map;
        for(auto i :nums){
            map[i]++;
        }
        for(auto &p : map){
            if(p.second > 1){
                ans = p.first;
            }
        }
        return ans;
    }
};