class Solution {
public:
    bool isPowerOfFour(int n) {
         if(n==1) return true;
        if(n<=0 || n==2 || n==3) return false;
        if(n%4!=0){  //agr 4 se divisible hi ni h then directly false
            return false;
        }
            
        n/=4;    //divide by 4 krte jaynge use br br agr rem!=0 , nd check krte jynge
       return  isPowerOfFour(n);
        
    }
};