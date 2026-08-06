class Solution {
public:
bool dfs(int n, vector<vector<int>>&adj, int source, int destination , vector<bool>& visit){
    if(source==destination) return true;
    visit[source]=true;
    for(int v: adj[source]){
        if(!visit[v]){
            if(dfs(n , adj , v , destination , visit)){
                return true;
            }
        }
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>visit(n, false);

        vector<vector<int>> adj(n);  //needed to create an adjacency list , to traverse all the neighbours of each node.
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(n , adj , source , destination , visit);
    }
};