class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int wsum=0;
        int count=0;
        for(int i=0;i<k;i++){
            wsum+=arr[i];
        }
        if(wsum>=threshold*k){
            count++;
        }
        int i=0;
        for(int j=k;j<n;j++){
            wsum=wsum+arr[j]-arr[i];
            if(wsum>=threshold*k){
                count++;
            }
            i++;
        }
        return count;
        
    }
};