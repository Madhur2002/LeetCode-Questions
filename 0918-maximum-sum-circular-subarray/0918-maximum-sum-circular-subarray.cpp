class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax = 0;
        int maxi = nums[0];
        int currMin = 0;
        int mini = nums[0];
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            
            currMax = max(nums[i] + currMax, nums[i]);
            maxi = max(currMax, maxi);
            
            currMin = min(nums[i] + currMin, nums[i]);
            mini = min(currMin, mini);
        }
        if(maxi < 0) return maxi;
        return max(maxi, sum-mini);
    }
};