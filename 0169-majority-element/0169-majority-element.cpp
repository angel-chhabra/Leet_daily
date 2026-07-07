class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int majorityElement;
        unordered_map<int , int> map;
        for(auto i: nums){
            map[i]++;
        }
        for(auto i: map){
            if(i.second>n/2){
                majorityElement=i.first;
            }
        }
        return majorityElement;
        
    }
};