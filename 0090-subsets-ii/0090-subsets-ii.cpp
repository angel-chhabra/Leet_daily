class Solution {
public:
void backtrack(vector<vector<int>>& result , vector<int>& nums , vector<int>& current , int indx){
     result.push_back(current); //is bar sbko puch krnge as every state is a valid subset here nd connstraints are diff 
     for(int i=indx;i<nums.size();i++){
        if(i>indx && nums[i]==nums[i-1]){  //when i is not the fisrt elemnt , it is obvoisuly the next one and duplicate as its previous one , then skip it!
            continue;  
        }
        current.push_back(nums[i]);  //everytime puch current elemnt
        backtrack(result ,nums , current , i+1);  // call everytime for every next elemnt
        current.pop_back();  //to undo
     }
    
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin() , nums.end());  //first sort as all duplicates can come together 
        backtrack(result , nums, current , 0);
        return result;
    }
};