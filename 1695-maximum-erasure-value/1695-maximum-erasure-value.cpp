class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int wsum=0;
        int maxi=INT_MIN;
        int freq[10001]={0};     //kyuki int 10000 tak ja skte h and index fr 9999 tak hi jayega so 10001 size 
        int j=0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;    //hr number ki freq calculate krte rho
            wsum+=nums[i];       //and sbka sum kyuki sum dena h ans m
            while(freq[nums[i]]>1){   //jse hi freq 1 se bdhti h kisi b num ki , window shrink krnge hm and freq--
                wsum=wsum-nums[j];
                freq[nums[j]]--;
                j++;
            }
            maxi=max(maxi , wsum);    //max sum ke lie
        }
        return maxi;
        
    }
};