class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int , int> map={{0,1}};
        int n=nums.size();
        int count=0;
        int curr_sum=0;
        for(auto i:nums){
            curr_sum+=i;
            int rem=(curr_sum%k+k)%k; //agr sum-ve aye to -ve integeres hi vo dhundega , thats why to get a +ve rem.
            if(map.count(rem)){     
                count+=map[rem];
            }
            map[rem]++;
        }
        return count;
        
    }
};