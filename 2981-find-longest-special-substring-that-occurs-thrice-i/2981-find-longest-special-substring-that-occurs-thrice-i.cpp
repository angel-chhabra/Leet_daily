class Solution {
public:
    int maximumLength(string s) {
        int length=0;
        int maxi=-1;
        unordered_map<string ,int> map;
        for(int i=0;i<s.size();i++){
            string str="";     //hr type ki substr check krte jaynge hr s[i] ko add krte krte
            for(int j=i;j<s.size();j++){
                if(s[i]==s[j]){    //agr chars same same h to str m plus kro coz we want special substr
                    str+=s[i];
                    map[str]++;  //hr us special substr ki freq store kro in map
            } else{
                break;
            }
            }
        }
            for(auto [k,v]:map){
                if(v>=3){     // map traverse krte hue jis b substr ki freq>=3 hogi uski length lenge and check w maxi
                    length =(int)k.size();
                    maxi=max(length , maxi);
                }

            }
            return maxi;
    }
};