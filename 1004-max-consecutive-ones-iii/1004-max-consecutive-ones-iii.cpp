class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0;
        int zeroes=0;
        int n=nums.size();
        int j=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]==0){      //agr right m zero aari h to zeroes++ hoga 
                zeroes++;
            }
            while(zeroes>k){    //jse hi zeroes bdgyi k se , to hm window shrink krna start krnge , or agr shrink krte krte left me 0 aya to zeroes ka count b decrease krnge
                if(nums[j]==0){
                    zeroes--;
                }
                j++; 
            }
            count=max(count , i-j+1);    //max of count and jo possible subarray size hoga 

        }
        return count;  
    }
};