class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {  //smae as next greater elemnt , bss isme bich ka size store krana h ans m 
        int n=temperatures.size();
        vector<int> ans(n);
        stack<int> stack;
        stack.push(n-1);
        ans[n-1]=0;
        for(int i=n-2;i>=0;i--){
            while(!stack.empty() && temperatures[stack.top()]<=temperatures[i]){
                stack.pop();
            }
            if(stack.empty()){
                ans[i]=0;
            } else{
                ans[i]=stack.top()-i;  //diff btw the indices
            }
            stack.push(i);
        }
        return ans;
    }
};