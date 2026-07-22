class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int freq[100001]={0};
        int num=0;
        for(auto i : nums){
            freq[i]++;
            if(freq[i]>1){
                num=i;
            }
        }
        return num;
    }
};