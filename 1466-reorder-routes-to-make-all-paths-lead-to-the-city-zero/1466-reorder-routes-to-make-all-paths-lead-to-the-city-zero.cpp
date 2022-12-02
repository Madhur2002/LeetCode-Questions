const int N = 5e4 + 5;
class Solution {
public:
   vector<int> graph1[N];
   vector<int> graph2[N];
   int minReorder(int n, vector<vector<int> >& e){
      map<int, int> in;
      for (auto& it : e) {
         graph1[it[0]].push_back(it[1]);
         graph2[it[1]].push_back(it[0]);
      }
      vector<int> dist(n, N + 10);
      int ret = 0;
      in[0] = 0;
      dist[0] = 0;
      queue<int> q;
      q.push(0);
      set<int> visited;
      visited.insert(0);
      while (!q.empty()) {
         int node = q.front();
         q.pop();
         ret += dist[node];
         for (auto& it : graph2[node]) {
            if (!visited.count(it) && dist[it] > 0) {
               dist[it] = 0;
               q.push(it);
               visited.insert(it);
            }
         }
         for (auto& it : graph1[node]) {
            if (!visited.count(it) && dist[it] > 1) {
               dist[it] = 1;
               q.push(it);
               visited.insert(it);
            }
         }
      }
      return ret;
   }
};