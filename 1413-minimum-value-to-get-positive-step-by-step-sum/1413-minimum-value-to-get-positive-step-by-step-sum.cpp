class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum=0;
        int mini=0;
        for(int i:nums){
            sum+=i;    //har bar sum m add krte jaynge current traversed elemnet ko
            mini=min(sum,mini);   //mini m hmesha min value store rhegi -ve or +ve
        }
        return 1-mini;     //taaki -ve value bhi na aaye and vo sum>=1 wali chiz hmesha satisfied rhe
    }
};