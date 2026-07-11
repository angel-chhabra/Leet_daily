class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int , int>map;
        for(int i=0;i<n;i++){ 
            if(map.find(nums[i])!=map.end()){   //agr curr element already present in map to uske map wale idx and abhi wale idx ka abs nikal lo and check 
                if(abs(i-map[nums[i]])<=k){
                    return true;
                }
            }
            map[nums[i]]=i;   //hr num ka indx store krte jare h uske sth , map[i]++ nhi use kia coz vo freq store krta
        }
        return false;
        
    }
};