class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<end){
            int mid=start +(end-start)/2;
            if(nums[mid]>nums[n-1]){     //rotate hone ke baad hmare age wale num last num se hmesha bde honge
                start=mid+1;
            } else{
                end=mid;
            }
        }
        return nums[start];
        
    }
};