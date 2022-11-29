class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& path, int node){
        path.push_back(node);
        
        if(node == graph.size() - 1){
            ans.push_back(path);
        }else{
            for(auto node: graph[node]){
                dfs(graph, ans, path, node);
            }
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;
        dfs(graph, ans, path, 0);
        return ans;
    }
};