class Solution {
public:
    double myPow(double x, long long n) {
        if(n==0) return 1;
        if(n<0){
            n=-n;   // n ko wps +ve bhi bnan pdega so as to calculate pow
            return myPow(1/x , n);
        }
        double val= myPow(x , n/2);
        if(n%2==0){
            return val *val;
        } else{
            return val * val * x;
        }
 }
};