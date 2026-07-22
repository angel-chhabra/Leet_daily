class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        while(i<n){
            int idx = nums[i] -1;
            if(nums[i] != nums[idx]){
                swap(nums[i],nums[idx]);
            } else{
                if(nums[i] != i+1){
                    return nums[i];
                }
                i++;
            }
        }
            return -1;
    }
};