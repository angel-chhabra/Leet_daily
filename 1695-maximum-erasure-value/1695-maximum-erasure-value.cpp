class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int wsum=0;
        int maxi=INT_MIN;
        int freq[10001]={0};
        int j=0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            wsum+=nums[i];
            while(freq[nums[i]]>1){
                wsum=wsum-nums[j];
                freq[nums[j]]--;
                j++;
            }
            maxi=max(maxi , wsum);
        }
        return maxi;
        
    }
};