class Solution {
public:
    bool isPowerOfThree(int n) {  
        int start=0;   // x ki range 0 se 30 hogi , as integer ki range itni hi hoti h
        int end=30;
        while(start<=end){
            int mid=start +(end-start)/2;
            if(pow(3 , mid)==n){
                return true;
            } else if(pow(3 , mid)>n){
                end=mid-1;
            } else{
                start=mid+1;
            }
        }
        return false;
    }
};