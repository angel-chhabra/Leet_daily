class Solution {
public:
//maily we eed to tell wether topo sort is possile or not , for that we will check if graph is acyclic the topo sort ca e done otherwise ot. therefore we use the Cycle checking in dir graph method of dfs!
bool isCycle(int src , vector<bool>&visit , vector<bool>&recpath , vector<vector<int>>& prerequisites){
    visit[src]=true;
    recpath[src]=true;
    for(int i=0;i<prerequisites.size();i++){ //list of neighbors not possible so travered the graph edges and then its vertices in the form[v, u].
        int u=prerequisites[i][1];
        int v=prerequisites[i][0];
        if(u==src){  //all the u ke valid neighours
          if(!visit[v]){
            if(isCycle(v , visit , recpath , prerequisites)){
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;  //v<----u (ulte de rkhe h yha pr)
        vector<bool>visit(V , false);
        vector<bool> recpath(V,false);

        for(int i=0;i<V;i++){
            if(!visit[i]){
               if(isCycle(i , visit , recpath , prerequisites)){   //O(V+E)
                return false;
               }
            }
        }
        return true;
    }
};