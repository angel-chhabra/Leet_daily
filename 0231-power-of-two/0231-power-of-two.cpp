class Solution {
public:
    bool isPowerOfTwo(int n) { 
        // return ( n >0 && ( n & (n-1))==0);   O(1) TC
        int start=0;    //int ranges from 2^0 to 2^30   O(1) TC
        int end=30; 
        while(start<=end){
            int mid=start + (end -start)/2;
            if(pow(2,mid)==n){
                return true;
            } else if(pow(2 , mid)<n){
                start=mid+1;
            } else{
                end=mid-1;
            }
        }
        return false;
    }
};