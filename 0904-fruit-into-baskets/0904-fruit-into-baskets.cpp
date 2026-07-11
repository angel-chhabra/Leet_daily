class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int j=0;
        int count=0;
        unordered_map<int , int> map;
        for(int i=0;i<n;i++){
            map[fruits[i]]++;    //window bnayi h and hr fruit ki freq add kri map m

            while(j<n && map.size()>2){    //jse hi map 2 se bda hota h hm starting wale fruit ko minus krnge
                map[fruits[j]]--;
                if(map[fruits[j]]==0){     //pehla fruit jab minus krnge to uski freq 0 hojegi and us fruit ko bhi to remove krna pdega map se 
                    map.erase(fruits[j]);
                }
                j++;
            }
            count=max(count , i-j+1);
        }
        return count;
    }
};