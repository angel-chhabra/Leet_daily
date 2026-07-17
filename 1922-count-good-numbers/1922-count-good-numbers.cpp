class Solution {
public:
int m=1e9+7;
long long power(int x , long long n){
    if(n>0){
        if(x==1) return 1;
        if(n%2==0){  //even position pr
            long long res=power(x , n/2)%m; 
            return (res*res)%m;
        } else{  //odd position
            long long res=power(x , n/2)%m;
            return(((res*res)%m)*x)%m;
        }
    }
    return 1;
}
    int countGoodNumbers(long long n) {
        // int product= a*b*c*d;
        // int product=(((((a*b)%m)*c)%m)*d)%m;
        long long res=power(20 , n/2);
        if(n%2==0) return res%m;
        else return(res*5)%m;
    }
};