class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int , int> map;
        int freq[128]={0};
        int maxfreq=0;
        int maxi=INT_MIN;
        int j=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
            maxfreq=max(maxfreq , freq[s[i]]);      // jis b letterki maxfreq h usko lia 
            while(j<s.size() && ((i-j+1)-maxfreq)>k){   //then checked ki curr length ki window m se agr max freq wale letter ko nikale to kya bche hue letter utne h ki vo allowed replacement jitni hojaenge??
                freq[s[j]]--;    //if zyda h to window shrink and perfectly k ke equal hote hi calculate length!
                j++;
            }
            maxi=max(maxi , i-j+1);

        }
        return maxi;
    }
};