class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string w="123456789";    //is tring m hi to lgegi hmari sliding window
        for(int i=2;i<=9;i++){   //window size needs to be b/w 2 and 9
            for(int j=0;j<=w.size()-i;j++){   //0 se start krnge nd jab tk total size-i ki window chiye hme
                int num=stoi(w.substr(j,i));   // w ki window bnai substr lekr
                if(num>=low && num<=high){   //agr low se high ke bich m h to
                    ans.push_back(num);    
                }
            }
        }
        return ans;
        
    }
};