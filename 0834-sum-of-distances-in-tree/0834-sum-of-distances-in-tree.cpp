class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(N);
        for (const auto& e : edges)
        {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        vector<int> sz(N, 0);
        int totalDist = 0;
        countSize(-1, 0, g, sz, totalDist, 0);
        vector<int> res(N, 0);
        getDist(N, -1, 0, totalDist, g, sz, res);
        return res;
    }

private:
    void countSize(int from, int to, vector<unordered_set<int>>& g, vector<int>& sz, int& totalDist, int currDist)
    {
        totalDist += currDist;
        int currSize = 1;
        for (const auto& adj : g[to])
        {
            if (adj != from)
            {
                countSize(to, adj, g, sz, totalDist, currDist + 1);
                currSize += sz[adj];
            }
        }
        sz[to] = currSize;
    }

    void getDist(int N, int from, int to, int currDist, vector<unordered_set<int>>& g, vector<int>& sz, vector<int>& res)
    {
        res[to] = currDist;
        for (const auto& adj : g[to])
            if (adj != from)
                getDist(N, to, adj, currDist - sz[adj] + N - sz[adj], g, sz, res);
    }
};