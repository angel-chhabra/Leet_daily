class Solution {
public:
    bool isPowerOfThree(int n) {  
        int start=0;   // x ki range 0 se 30 hogi , as integer ki range itni hi hoti h
        int end=30;
        while(start<=end){
            int mid=start +(end-start)/2;
            double val=pow(3 , mid);
            if(val==n){
                return true;
            } else if(val>n){
                end=mid-1;
            } else{
                start=mid+1;
            }
        }
        return false;
    }
};