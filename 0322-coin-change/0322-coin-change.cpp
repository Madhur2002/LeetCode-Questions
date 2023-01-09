class Solution {
// private:
//     int solve(vector<vector<int>>dp, vector<int>& coin, int amount, int ind){
//         if(ind == 0){
//             if(amount % coin[0] == 0) return amount/coin[0];
//             return 1e9;
//         }
//         if(dp[ind][amount] != -1) return dp[ind][amount];
//         int not_take = solve(dp, coin, amount, ind-1);
//         int take = INT_MAX;
//         if(coin[ind] <= amount) take = 1 + solve(dp, coin, amount-coin[ind], ind);
//         return dp[ind][amount] = min(take, not_take);
//     }
public:
    int coinChange(vector<int>& coin, int amount) {
        int n = coin.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        
        for(int i=0; i<=amount; i++){
            if(i % coin[0] == 0){
                dp[0][i] = i/coin[0];
            }else{
                dp[0][i] = 1e9;
            }
        }
        for(int i=1; i<n; i++){
            for(int tar=0; tar<=amount; tar++){
                int not_take = dp[i-1][tar];
                int take = INT_MAX;
                if(coin[i] <= tar) take = 1 + dp[i][tar - coin[i]];
                dp[i][tar] = min(take, not_take);
            }
        }
        int ans = dp[n-1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};