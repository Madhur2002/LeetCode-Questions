class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n+2);
        // dp[n] = 0;
        // dp[n+1] = 0;
        // for(int i=n-1; i>=0; i--){
        //     dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        // }
        // return min(dp[0], dp[1]);
        int prev = 0;
        int prev2 = 0;
        for(int i=n-1; i>=0; i--){
            int curr = cost[i] + min(prev, prev2);
            prev2 = prev;
            prev = curr;
        }
        return min(prev, prev2);
    }
};