class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int product=1;
        int maxi=INT_MIN;
        int i=0 , j=n-1;
        // while(i<n && j>=0){
        //     product=(nums[i++]-1)*(nums[j--]-1);
        //     maxi=max(maxi , product);
        //     // i++;
        //     // j--;
        // }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                product=(nums[i]-1)*(nums[j]-1);
                maxi=max(maxi , product);
            }
        }
        return maxi;
        
    }
};