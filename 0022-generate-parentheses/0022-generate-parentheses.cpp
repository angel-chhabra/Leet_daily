class Solution {
public:
void solve(vector<string>& result ,string curr , int open , int close , int n){
    if(curr.size()==2*n){    //agr size bdjayega n(opening)+n(closing) se then return
        result.push_back(curr);
        return;
    }
    if(open<n){  //open agar lesser than given n , then aap or open dal skte ho
        solve(result ,curr+"(" , open+1 , close , n);
    }
    if(close<open){   //agr close kam h open se to or close dal skte ho 
        solve(result ,curr+")" , open , close+1 , n);
    }
}
    vector<string> generateParenthesis(int n) {
        string curr="";
        vector<string> result;
        solve(result , curr , 0 , 0, n);
        return result;    
    }
};