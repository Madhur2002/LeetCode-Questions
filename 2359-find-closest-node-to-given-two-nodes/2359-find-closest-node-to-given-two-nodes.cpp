class Solution {
private:
    void path_node(int node, int dist, vector<int>& edges, vector<int>& path){
        
        if(node != -1 && path[node] == -1){
            path[node] = dist;
            path_node(edges[node], dist+1, edges, path);
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int ans = -1;
        int mindis = INT_MAX;
        int n = edges.size();
        
        vector<int> path1(n, -1);
        vector<int> path2(n, -1);
        
        path_node(node1, 0, edges, path1);
        path_node(node2, 0, edges, path2);
        
        for(int i=0; i<n; i++){
            if(min(path1[i], path2[i]) >= 0 && max(path1[i], path2[i]) < mindis){
                mindis = max(path1[i], path2[i]);
                ans = i;
            }
        }
        return ans;
        
        
        
    }
};