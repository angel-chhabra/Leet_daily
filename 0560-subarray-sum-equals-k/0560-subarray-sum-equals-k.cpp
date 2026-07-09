class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count =0;
        int n=nums.size();
        int curr_sum=0;
        unordered_map<int , int> map={{0,1}};    //to store the freq of sums 
        for(auto i:nums){
            curr_sum+=i;                      //sum banate jao hr element se 
            if(map.count(curr_sum-k)){        // curr_sum-old_sum=k hota h , so we'll check if(curr_sum-k) is present?
                count+=map[curr_sum-k];       //jitni bar b prsent h count m daldo
            }
            map[curr_sum]++;               // next wale pr chlte h ab
        }
        return count;
    }
};