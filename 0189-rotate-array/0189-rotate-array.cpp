class Solution {
public:
// void reverse(vector<int>& nums , int start , int end){
//            while(start<end){
//             swap(nums[start] , nums[end]);
//             start++;
//             end--;
//            }
//         }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        // int i=0 , j=n-k-1;
        // int a =j+1 , b=n-1;
        // reverse(nums,i , j);
        // reverse(nums , a ,b);
        // reverse(nums ,0 , n-1);

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        
    }
};