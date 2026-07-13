class Solution {
public:
    int maximumLength(string s) {
        int length=0;
        int maxi=-1;
        unordered_map<string ,int> map;
        for(int i=0;i<s.size();i++){
            string str="";
            for(int j=i;j<s.size();j++){
                if(s[i]==s[j]){
                    str+=s[i];
                    map[str]++;
            } else{
                break;
            }
            }
        }
            for(auto [k,v]:map){
                if(v>=3){
                    length =(int)k.size();
                    maxi=max(length , maxi);
                }

            }
            return maxi;
    }
};