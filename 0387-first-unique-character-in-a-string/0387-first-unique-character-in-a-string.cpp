class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26]={0};
        queue<char> q;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            q.push(ch);
            freq[ch-'a']++;

            while(!q.empty() && freq[q.front()-'a']>1){
                q.pop();
            }
        }
        if(q.empty()){
                return -1;
            } 

        char target=q.front();
        for(int i=0;i<s.size();i++){
            if(s[i]==target){
                return i;
            }
        }
        return -1;
    }
};