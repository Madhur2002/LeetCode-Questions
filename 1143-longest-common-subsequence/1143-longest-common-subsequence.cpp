class Solution {
// private:
//     int solve(vector<vector<int>>dp, int ind1, int ind2, string s1, string s2){
//         if(ind1 == 0 || ind2 == 0){
//             return 0;
//         }
//         if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
//         if(s1[ind1-1] == s2[ind2-1]) return dp[ind1][ind2] = 1 + solve(dp, ind1-1, ind2-1, s1, s2);
//         return dp[ind1][ind2] = max(solve(dp, ind1-1, ind2, s1, s2), solve(dp, ind1, ind2-1, s1, s2));
//     }
public: 
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=m; i++){
            dp[0][i] = 0;
        }
        for(int i=0; i<=n; i++){
           dp[i][0] = 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};