class Solution {
private:
    void dfs(vector<int>adjLs[], vector<vector<int>>& isConnected, int node, vector<int>& vis){
        vis[node] = true;
        for(auto it: adjLs[node]){
            if(!vis[it])
                dfs(adjLs, isConnected, it, vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adjLs[V]; 
        
        // to change adjacency matrix to list 
        for(int i = 0;i<V;i++) {
            for(int j = 0;j<V;j++) {
                // self nodes are not considered
                if(isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        vector<int>vis(V, false);
        int count = 0;
        for(int i=0; i < isConnected.size(); i++){
            if(!vis[i]){
                count++;
                dfs(adjLs, isConnected, i, vis);
            }
        }
        return count;
    }
};