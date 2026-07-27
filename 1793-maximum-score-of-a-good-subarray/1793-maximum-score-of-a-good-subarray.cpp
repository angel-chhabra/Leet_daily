class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        stack<int> stack;
        vector<int> nsl(n);
        vector<int> nsr(n);
        int ans=0;
        for(int i=0;i<n;i++){    //nsl
            while(!stack.empty() && nums[stack.top()]>=nums[i]){
                stack.pop();
            }
            if(stack.empty()){
                nsl[i]=-1;
            } else{
                nsl[i]=stack.top();
            }
            stack.push(i);
        }
        while(!stack.empty()){
            stack.pop();
        }

        for(int i=n-1;i>=0;i--){ //nsr
            while(!stack.empty() && nums[stack.top()]>=nums[i]){
                stack.pop();
            }
            if(stack.empty()){
                nsr[i]=n;
            } else{
                nsr[i]=stack.top();
            }
            stack.push(i);
        }
        for(int i=0;i<n;i++){
            if(nsl[i]<k && nsr[i]>k){   //jo b nums[i] left wale smallest se bda and right wale smallest se chota hoga vo min hoga uss subarray ka , so taking it 
                int length=nsr[i]-nsl[i]-1;  //length of that good subaray
                ans=max(ans , length*nums[i]);
            }
        }
        return ans;
        
    }
};