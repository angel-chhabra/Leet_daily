class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){     //agr pehle hi s1 bda hoga so not possible ki vo s2 ke andar ho
            return false;
        }
       vector<int> v1(26,0);   //for s1 freq count
       vector<int> v2(26,0);   //for s2 freq count
       for(int i=0;i<s1.size();i++){
        v1[s1[i]-'a']++;        //s1 ki count ginli
        v2[s2[i]-'a']++;        //s2 ki first window bnali s1 ki frq count jitni hi
       }
       if(v2==v1){
         return true;
       }

       int j=0; 
       for(int i=s1.size();i<s2.size();i++){
        v2[s2[i]-'a']++;      //right char add and left char subtract
        v2[s2[j]-'a']--;

        if(v2==v1){
            return true;
        }
        j++;
       }
        return false;
        
    }
};