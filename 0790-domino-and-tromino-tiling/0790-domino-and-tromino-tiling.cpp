class Solution {
// private:
//     int solve(int n){
//         if(n==1 || n==2) return n;
//         if(n==3) return 5;
//         return 2*solve(n-1) + solve(n-3);
//     }
public:
    int mod = 1000000007;
    int numTilings(int n) {
        if(n==1 || n==2) return n;
        vector<int>dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i=4; i<=n; i++){
            dp[i] = (2*dp[i-1]%mod + dp[i-3]%mod)%mod;
        }
        return dp[n];
    }
};