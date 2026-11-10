class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;
        int n=graph.size();
        vector<int>colour(n, -1); //no need of visit vector as agar colour=-1 to mtlb visit hi nhi hua tbi colour nhi assign hua and if visited colour=0/1
       for(int i=0;i<n;i++){  //for any of the disconnected components
        if(colour[i]==-1){
            q.push(i);
            colour[i]=0;

        while(q.size()>0){
            int u=q.front();
            q.pop();
            for(int v:graph[u]){
                if(colour[v]==-1){
                    colour[v]=!colour[u];
                    q.push(v);
                }
                else{
                    if(colour[v]==colour[u]){
                        return false;
                    }
                }
            }
        } 
        }
       }
        return true;
    }
};