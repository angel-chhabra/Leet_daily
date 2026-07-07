class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=0;
        for(int i: nums){
            if(count==0){
                candidate=i;
            }
            if(i==candidate){
                count++;
            } else{
                count--;
            }
        }
        return candidate;




        // int n=nums.size();
        // int majorityElement;       //learn its algorithm also , moore voting algorithm
        // unordered_map<int , int> map;
        // for(auto i: nums){
        //     map[i]++;
        // }
        // for(auto i: map){
        //     if(i.second>n/2){
        //         majorityElement=i.first;
        //     }
        // }
        // return majorityElement;
        
    }
};