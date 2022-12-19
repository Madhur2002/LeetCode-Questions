class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>>mp;
        for(auto x : edges){
            int u = x[0];
            int v = x[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool>vis(n+1, false);
        queue<int>q;
        q.push(source);
        vis[source] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
             
            for(auto x: mp[node]){
                if(!vis[x]){
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
        return vis[destination];
    }
};