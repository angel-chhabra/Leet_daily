class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        long long count=0;
        int product=1;
        int j=0;
        if(k<=1){    //impossible hua ye to
            return 0;
        }
        for(int i=0;i<n;i++){
            product=product*nums[i];   //product calculate krte jaynge hr bar windo bna bnakr

            while(product>=k){
                product=product/nums[j];   //hr bar window shrink krte jaynge agr product bda ya equal jara h
                j++;
            }
              count+=(i-j+1);       //us subarray ki sari possible permutations ajyngi is i-j+1 se to sbko count krnge

        }
        return count;
    }
};