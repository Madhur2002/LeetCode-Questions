class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> v(n+1);

        for(auto r: roads) {
            int s = r[0];
            int e = r[1];
            int d = r[2];
            v[s].push_back({e, d});
            v[e].push_back({s, d});
        }
        int minD = INT_MAX;
        queue<int> q;
        q.push(1);
        vector<int> vis(n+1, 0);
        vis[1] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto x: v[node]) {
                minD = min(minD, x.second);
                if(vis[x.first] == 0) {
                    vis[x.first] = 1;
                    q.push(x.first);
                }
            }
        }
        return minD;
    }
};