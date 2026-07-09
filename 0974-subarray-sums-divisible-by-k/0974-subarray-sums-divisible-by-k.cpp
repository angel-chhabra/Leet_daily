class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int , int> map={{0,1}};
        int n=nums.size();
        int count=0;
        int curr_sum=0;
        for(auto i:nums){
            curr_sum+=i;
            if(map.count((curr_sum%k+k)%k)){
                count+=map[(curr_sum%k+k)%k];
            }
            map[(curr_sum%k+k)%k]++;
        }
        return count;
        
    }
};