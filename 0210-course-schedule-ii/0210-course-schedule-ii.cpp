class Solution {
public:
bool isCycle(int src , vector<bool>&visit , vector<bool>&recpath , vector<vector<int>>& graph){
    visit[src]=true;
    recpath[src]=true;
    for(int i=0;i<graph.size();i++){ //list of neighbors not possible so travered the graph edges and then its vertices in the form[v, u].
        int u=graph[i][1];
        int v=graph[i][0];
        if(u==src){  //all the u ke valid neighours
          if(!visit[v]){
            if(isCycle(v , visit , recpath , graph)){
                return true;
            }
          } else{
            if(recpath[v]){
                return true;
            }
          }
        }
    }
        recpath[src]=false;
        return false;
}
void toposort(int src ,vector<bool>&vis2 , stack<int>&s , vector<vector<int>>& graph){
        vis2[src]=true;
        for(int i=0;i<graph.size();i++){
            int u=graph[i][1];
            int v=graph[i][0];
            if(u==src){  //all the u ke valid neighours
          if(!vis2[v]){
           toposort(v , vis2 , s , graph);
        }
        }
     }
     s.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& graph) {
        int V=numCourses;
        vector<bool>visit(V , false);
        vector<bool>recpath(V , false);
        vector<int> ans;

        for(int i=0;i<V;i++){
            if(!visit[i]){
                if(isCycle(i , visit , recpath , graph)){
                    return ans;
                }
            }
        }
        //perform topological sort now!
        vector<bool>vis2(V, false);
        stack<int>s;
        for(int i=0;i<V;i++){
            if(!vis2[i]){
                toposort(i , vis2 , s, graph);

            }
        } 

        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};