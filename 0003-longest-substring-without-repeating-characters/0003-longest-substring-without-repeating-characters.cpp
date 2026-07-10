class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int freq[128]={0};     //to store freq of chars , bigger size as for all the extra things too
        int j=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            freq[ch]++;      //hr char ki freq count krte jaynge

            while(freq[ch]>1){   //jse hi freq bdi hojaegi 1 se , window shrink krnge  j elemnt ki freq - krnge
                freq[s[j]]--;
                j++;
            }
            maxi=max(i-j+1, maxi);
        }
        return maxi;
        
    }
};