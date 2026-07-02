class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        vector<int> map(3,0);  // count sort lgaya and yha pr max hmesha 2 hi hoga 
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        vector<int> result;
        for(int i=0;i<=2;i++){
            if(map[i]>0){
                int count=map[i];
                for(int j=0;j<count;j++){
                    result.push_back(i);
                }
            }
        }    
        nums=result;    
    }
};