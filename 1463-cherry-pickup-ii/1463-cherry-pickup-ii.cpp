class Solution {
private:
    int solve(int i, int j1, int j2, int m, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n) return -1e8;
        if(i == m-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxAns = INT_MIN;

        for(int dj1 = -1; dj1 <= +1; dj1++){
            for(int dj2 = -1; dj2 <= +1; dj2++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += solve(i+1, j1+dj1, j2+dj2, m, n, grid, dp);
                maxAns = max(maxAns, value);
            }
        }
        return dp[i][j1][j2] = maxAns;

    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(0, 0, n-1, m, n, grid, dp);
        //on observing the question we can see that both the robots have same row
        //always as in all three possible moves we can see that row increases by +1
        //in all the cases so in any case both the robots will have to move by one row
        //in any move. 
    }
};