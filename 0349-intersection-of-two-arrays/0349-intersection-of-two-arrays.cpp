class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> set;
        for(int i: nums1){
            set.insert(i);
        }

        for(int i: nums2){
            if(set.find(i)!=set.end()){
                ans.push_back(i);
            }
            set.erase(i);
    
        }
        return ans;
        
    }
};