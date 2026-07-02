class Solution {
public:
int minimum(vector<int>& nums){
    int n=nums.size();
    int start=0;
    int end=n-1;
    while(start<end){
        int mid=start+(end-start)/2;
        if(nums[mid]>nums[n-1]){
            start=mid+1;
        } else{
            end=mid;
        }
    }
    return start;
}
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int min=minimum(nums);
        int start = 0;
        int end=min;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            } else if(nums[mid]>target){
                end=mid-1;
            } else{
                start=mid+1;
            }
        }
        start=min;
        end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            } else if(nums[mid]>target){
                end=mid-1;
            } else{
                start=mid+1;
            }
        }    
        return -1;    
    }
};