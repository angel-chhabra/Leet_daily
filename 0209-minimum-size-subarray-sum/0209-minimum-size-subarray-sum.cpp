class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minisize=INT_MAX;
        int wsum=0;
        int n=nums.size(); 
        int j=0;
        for(int i=0;i<n;i++){
            wsum+=nums[i];
            while(wsum>=target){
                int size=i-j+1;
                minisize=min(size , minisize);

                wsum=wsum-nums[j];
                j++;
            }
        }
        if(minisize==INT_MAX){
            return 0;
        } else{
        return minisize;
        }
        }
};