class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                if(s[i] == s[j]) {
                    if(j-1 < 0) dp[i][j] = 1;
                    else dp[i][j] = dp[i+1][j-1] + 1;
                }
                else {
                    if(j-1 < 0) dp[i][j] = dp[i+1][j];
                    else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                } 
            }
        }
        return n - dp[0][n-1];
    }
};