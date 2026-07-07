class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int maxLength=0;
        int length=1;
        for(int i: nums){
            set.insert(i);
        }
        for(int i: set){
            if(set.find(i-1)==set.end()){
                int a=i;
                length=1;
                while(set.find(a+1)!=set.end()){
                    length++;
                    a++;
                }
                maxLength=max(maxLength , length);
            
        }
        }
        return maxLength; 
    }
};