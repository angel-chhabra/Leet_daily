class Solution {
public:
bool isVowel(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
    int maxVowels(string s, int k) {
        int n=s.size();
        int count=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                count++;
            }
        }
        int maxi=count;
        int i=0;
        for(int j=k;j<n;j++){
            if(isVowel(s[j])){
                count++;
            }
            if(isVowel(s[i])){
                count--;
            }
            i++;
        maxi=max(count , maxi);
        }
        return maxi;
        
    }
};