class Solution {
private:
    int solve(int ind, int buy, int transc, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(transc == 0){
           return 0;
        }
        if(ind == n) return 0;
        if(dp[ind][buy][transc] != -1) return dp[ind][buy][transc];
        long profit = 0;
        if(buy){
            profit = max(-prices[ind] + solve(ind+1, 0, transc, prices, dp), solve(ind+1, 1, transc, prices, dp));
        }else{
            profit = max(prices[ind] + solve(ind+1, 1, transc-1, prices, dp), solve(ind+1, 0, transc, prices, dp));
        }
        return dp[ind][buy][transc] = profit;
    }
public:
    int n;
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, 1, k, prices, dp);
    }
};