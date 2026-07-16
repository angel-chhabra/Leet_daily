class Solution {
public:
void backtrack(vector<int>& nums , vector<int>& current , vector<vector<int>>& result , int index){
    if(index==nums.size()){    //agr index last m phuch gya mena sour path is done now add these to final result
        result.push_back(current);  //current is a sample array made to track which elemnts we r including nd excluding
        return;
    }
    current.push_back(nums[index]);  //present push kia current m and start the path with including it
    backtrack(nums , current , result , index+1);

    current.pop_back();   //present wala pop kraya as this timw we want to exclude it.
    backtrack(nums , current , result , index+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int>current;
        backtrack(nums , current , result , 0);

        return result;
        
    }
};