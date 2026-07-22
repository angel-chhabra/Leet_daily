class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string i: operations){
            if(i=="C"){       //c ayega to hta do stack se
                st.pop();
            }
             else if(i=="D"){
                st.push(st.top()*2);   // d hoga to double kr ke add krdo
            } else if(i=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.push(a);   //a ko wps dlnge
                st.push(a+b);  //or sum ko b kyuki + h 
            }
            else{
                st.push(stoi(i));  // else case m int hi hoga so convert string to int and push in stack
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();  //sum krdo 
            st.pop();
        }
        return ans;
    }
};