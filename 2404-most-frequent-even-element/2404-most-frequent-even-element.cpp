class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int , int> map;
        for(auto i:nums){
            if(i%2==0){   //agar even h to hi map m dalnge
            map[i]++;
            }
        }
        int ans=-1;
        int maxcount=0; 
            for(auto i:map){
                if(i.second>maxcount){
                    maxcount=i.second;
                    ans=i.first;
                }
            }
        return ans;
    }
};