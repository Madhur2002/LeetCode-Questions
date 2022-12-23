class Solution {
private:
    bool solve(int i, vector<vector<int>>& dp, vector<int>& nums, int target){
        if(target == 0) return true;
        if(i == 0) return (nums[0] == target);
        if(dp[i][target] != -1) return dp[i][target]; 
        
        bool not_take = solve(i-1, dp, nums, target);
        bool take = false;
        if(nums[i] <= target){
            take = solve(i-1, dp, nums, target-nums[i]);
        }
        return dp[i][target] = take || not_take;
    }
public:
    bool canPartition(vector<int>& nums) {
        int m = nums.size();
        int sum = 0;
        for(int i=0; i<m; i++){
            sum += nums[i];
        }
        if(sum%2 != 0) return false;
        else{
            int k = sum/2;
            vector<vector<bool>>dp(m, vector<bool>(k+1, 0));
            for(int i=0; i<m; i++){
                dp[i][0] = true;
            }
            if(nums[0] <= k) dp[0][nums[0]] = true;
            for(int i=1; i<m; i++){
                for(int target=1; target<=k; target++){
                    bool not_take = dp[i-1][target];
                    bool take = false;
                    if(nums[i] <= target) take = dp[i-1][target-nums[i]];
                    dp[i][target] = take || not_take;
                }
            }
            return dp[m-1][k];
        }
    }
};