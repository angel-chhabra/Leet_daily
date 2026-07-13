class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        int maxi=-1;
        int runninglen=0;
        char prevletter='@';
        vector<vector<int>> vec(26 , vector<int>(n+1 , 0));
        for(char c :s){
            if(c==prevletter){
                runninglen++;
            } else{
                runninglen=1;
                prevletter=c;
            }
            vec[c-'a'][runninglen]++;
        }
        for(int i=0;i<26;i++){
            int count=0;
            for(int j=n;j>=1;j--){
                count+=vec[i][j];
                if(count>=3){
                    maxi=max(maxi , j);
                }
            }

        }
        return maxi;

        
    }
};