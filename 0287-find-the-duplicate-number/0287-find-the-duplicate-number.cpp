class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];  //ye to krna hi krna h phle 
            fast=nums[nums[fast]];
        } while(slow!=fast);   //jb tk equal n hota (kind of detecting cycle)

        slow=nums[0];    //jse hi detect hojaye now , slow reset to head
        while(slow!=fast){     
            slow=nums[slow];   //fr jb tk equal n hote ek ek krke chlnge
            fast=nums[fast];
        }
        return slow;  //or fast , as now both are at duplicates
        
    }
};