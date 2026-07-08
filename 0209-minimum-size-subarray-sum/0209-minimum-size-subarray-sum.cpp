class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minisize=INT_MAX;   //to maintain the min length of subarray
        int wsum=0;
        int n=nums.size(); 
        int j=0;
        for(int i=0;i<n;i++){  
            wsum+=nums[i];     //window calculate krte rhnge ek ek element add kr kr ke
            while(wsum>=target){
                int size=i-j+1;    //size of window jab bhi uska wsum >=target ho 
                minisize=min(size , minisize);    

                wsum=wsum-nums[j];    //aage bdhna , kyuki aage bhi scope h or bhi chhota subarr milne ka w wsum>=target
                j++;                 //window ko aage bdhane k lie and first elemnt ko subtract krne k lie
            }
        }
        if(minisize==INT_MAX){
            return 0;
        } else{
        return minisize;
        }
        }
};