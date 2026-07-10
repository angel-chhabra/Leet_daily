class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0;
        int zeroes=0;
        int n=nums.size();
        int j=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroes++;
            }
            while(zeroes>k){
                if(nums[j]==0){
                    zeroes--;
                }
                j++;
            }
            count=max(count , i-j+1);

        }
        return count;  
    }
};