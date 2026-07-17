class Solution {
public:
    bool isPerfectSquare(int num) {
        int start=0;
        int end=num;
        while(start<=end){
            long long mid=start+(end-start)/2;
            if(mid*mid==num){
                if(floor(mid)==mid){
                    return true;
                }
            } else if(mid*mid<num){
                start=mid+1;
            } else{
                end=mid-1;
            }
        }
        return false;
        
    }
};