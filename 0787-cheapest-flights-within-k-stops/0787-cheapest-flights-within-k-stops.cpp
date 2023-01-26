class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>adj[n];
        for(auto& flight: flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {src, 0}});
        
        vector<int>dist(n, 1e9);
        dist[src] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            
            if(stops > k) continue;
            
            for(auto& it: adj[node]){
                int toNode = it.first;
                int weight = it.second;
                
                if(weight + dis < dist[toNode] && stops <= k){
                    dist[toNode] = weight + dis;
                    q.push({stops + 1, {toNode, weight+dis}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};