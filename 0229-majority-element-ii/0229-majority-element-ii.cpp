class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int , int> map;
        vector<int> ans;
        for(auto i: nums){
            map[i]++;
        }
        for(auto i:map){
            if(i.second>n/3){
                ans.push_back(i.first);
            }
        }
        return ans;
        
    }
};