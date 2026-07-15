class Solution {
public:
int BS(vector<int> nums , int tar , int left , int right){
    int mid=left+(right-left)/2;
    if(left>right) return -1;   //by recursion
    if(nums[mid]==tar) return mid;
    if(nums[mid]>tar){
       return BS(nums , tar , left , mid-1);
    } else{
        return BS(nums , tar , mid+1 , right);

    }
}
    int search(vector<int>& nums, int target) {
    return BS(nums , target , 0 , nums.size()-1);    
        
    }
};