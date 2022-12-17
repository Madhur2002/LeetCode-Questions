class Solution {
private:
    int helper2(vector<int>& dp2, vector<int>& nums, int index){
        if(index > nums.size()-1) return 0;
        if(index == nums.size()-1) return nums[nums.size() - 1];
        if(dp2[index] != -1) return dp2[index];
        int include = nums[index] + helper2(dp2, nums, index + 2);
        int exclude = helper2(dp2, nums, index + 1);
        int ans = max(include, exclude);
        return dp2[index] = ans;
    }
    int helper1(vector<int>& dp1, vector<int>& nums, int index){
        
        if(index >= nums.size()-1) return 0;
        // if(index == nums.size()) return nums[nums.size() - 1];
        if(dp1[index] != -1) return dp1[index];
        int include = nums[index] + helper1(dp1, nums, index + 2);
        int exclude = helper1(dp1, nums, index + 1);
        int ans = max(include, exclude);
        return dp1[index] = ans;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int>dp1(n+1, -1);
        vector<int>dp2(n+1, -1);
        int index = 0;
        int ans1 = helper1(dp1, nums, index);
        int ans2 = helper2(dp2, nums, index+1);
        return max(ans1, ans2);
    }
};