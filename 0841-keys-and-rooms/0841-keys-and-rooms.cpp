class Solution {
public:
void dfs(int u , vector<vector<int>>& rooms , vector<bool>&visit){  //casually visited all nodes bydfs.
    visit[u]=true;
    for(int v:rooms[u])
    if(!visit[v]){
        dfs(v , rooms , visit);
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visit(n, false);
        dfs(0 , rooms , visit);
        for(int i=0;i<n;i++){ //checked for disconnected components (same code as that) , if disconnected means ans would be false!
            if(!visit[i]){
                return false;
            } 
        }
        return true;
    }
};