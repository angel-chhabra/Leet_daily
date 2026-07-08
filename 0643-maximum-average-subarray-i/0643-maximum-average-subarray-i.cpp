class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n =nums.size();
        double wsum=0;
        for(int i=0;i<k;i++){
            wsum+=nums[i];
        }
        double maxi=wsum;
        int i=0;
        for(int j=k;j<n;j++){
            wsum=wsum+nums[j]-nums[i];
            maxi=max(maxi,wsum);
            i++;
        }
        return maxi/k;
    }
};