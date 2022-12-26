class Solution {
private:
    bool solve(vector<int>& dp, vector<int>& nums, int idx, int n){
        if(idx == n-1) return true;
        if(idx >= n) return false;
        if(dp[idx] != -1) return dp[idx];
        for(int i=1; i<=nums[idx]; i++){
            if(solve(dp, nums, idx+i, n)) return dp[idx] = true;
        }
        return dp[idx] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n ,-1);
        return solve(dp, nums, 0, n);
    }
};