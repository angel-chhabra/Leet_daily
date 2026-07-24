class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int> stack;
        unordered_map<int , int> map;
        for(int i=n-1;i>=0;i--){
            while(!stack.empty() && nums2[i]>=stack.top()){  //directly comparing the values and not the indices!
                stack.pop();
            }
            if(stack.empty()){
                map[nums2[i]]=-1;  // values of nums2 store kr rhe h map m along w their NGE
            } else{
                map[nums2[i]]=stack.top();
            }
            stack.push(nums2[i]);  //stack m b value push kr rhe h direct
        }
        vector<int> ans;
        for(int x: nums1){
            ans.push_back(map[x]);  //ab nums1 ko traverse krnge and use sare elemnts ko as a key, map m dhundnge and unki corresponding NGE value ans m push krnge 
        }
        return ans;
    }
};