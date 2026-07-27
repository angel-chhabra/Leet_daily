class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int> stack;
        vector<int> nsl(n);
        vector<int>nsr(n);

        for(int i=0;i<n;i++){  //nsl
            while(!stack.empty() && arr[stack.top()]>=arr[i]){
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

            for(int i=n-1;i>=0;i--){   //nsr
            while(!stack.empty() && arr[stack.top()]>arr[i]){  //not using >= due to duplicates
                stack.pop();
            }
            if(stack.empty()){
                nsr[i]=n;
            } else{
                nsr[i]=stack.top();
            }
            stack.push(i);
            }
        
            long long sum=0;
            const int MOD = 1e9 + 7;

            for(int i=0;i<n;i++){  //arr traversing
            long long left_choices=(i-nsl[i]);  //ki left side m kitni bar choice h min of subarr bnne ki
            long long right_choices=(nsr[i]-i);  //right side m kitni bar choice h min of subarr bnne ki
            sum=(sum+ arr[i]*left_choices%MOD * right_choices)%MOD;  //arr[i]*left contibution*right contribution
            }
            return sum;
    }
};