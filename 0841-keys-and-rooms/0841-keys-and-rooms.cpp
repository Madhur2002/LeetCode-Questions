class Solution {
private:
    void dfs(vector<vector<int>>& rooms, vector<bool>& vis, int node){
        vis[node] = true;
        for(auto x : rooms[node]){
            if(!vis[x]){
                dfs(rooms, vis, x);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>path;
        vector<bool>vis(n, false);
        dfs(rooms, vis, 0);
        for(int i=0; i<vis.size(); i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};