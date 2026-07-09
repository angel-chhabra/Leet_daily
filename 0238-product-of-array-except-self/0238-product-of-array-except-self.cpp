class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        vector<int> ans(n , 1);         // first elemnt taki 1 rhe hmara arrays 0 se bhra hua na ho
        for(int i=1;i<n;i++){              //prefix product
            ans[i]=ans[i-1]*nums[i-1];
        }
        int rightproduct=1;
        for(int i=n-1;i>=0;i--){           //suffix product
            ans[i]=ans[i]*rightproduct;
            rightproduct*=nums[i];       //kyuki hme nums[i] se multiply nhi krte rhna , hme hr bar jitne b nums[i] right m aate rhnge as loop goes forward , sbka right product chahiye hme and kyuki ans array m already suffix product store ho chuke h from 1 to n to ab n to 0 hmara dubara ans m nhi store kr skte vrna values overwrite
        }
        return ans;
        
    }
};