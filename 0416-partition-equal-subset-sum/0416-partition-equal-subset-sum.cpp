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
            vector<vector<int>>dp(m, vector<int>(k+1, -1));
            return solve(m-1, dp, nums, sum/2);
        }
    }
};