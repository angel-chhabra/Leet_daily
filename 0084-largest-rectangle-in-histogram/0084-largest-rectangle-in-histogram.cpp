class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> stack;
        vector<int> nsl(n);
        vector<int> nsr(n);

        nsl[0]=-1;
        stack.push(0);
        for(int i=1;i<n;i++){
        while(!stack.empty() && heights[stack.top()]>=heights[i]){
            stack.pop();
        }
        if(stack.empty()){
            nsl[i]=-1;
        } else{
            nsl[i]=stack.top();
        }
        stack.push(i);
        }
        while(!stack.empty()){
            stack.pop();
        }

        nsr[n-1]=n;
        stack.push(n-1);
        for(int i=n-2;i>=0;i--){
        while(!stack.empty() && heights[stack.top()]>=heights[i]){
            stack.pop();
        }
        if(stack.empty()){
            nsr[i]=n;
        } else{
            nsr[i]=stack.top();
        }
        stack.push(i);
     }

     int maxArea=0;
     for(int i=0;i<n;i++){
        int height=heights[i];
        int width=nsr[i]-nsl[i]-1;
        int area=height* width;

        maxArea=max(area , maxArea);
     }
     return maxArea;
    }
};