class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
//         vector<int>dp1(n, 0);
//         vector<int>dp2(n, 0);
//         int ans1 = -1;
//         // dp1 -> not including the last element
//        //  dp2 -> not including the first element        
//         dp1[0] = nums[0];
//         for(int i=1; i<n-1;i++){
//             int include = nums[i];
//             if(i > 1) include += dp1[i-2];
//             int exclude = dp1[i-1] + 0;
//             dp1[i] = max(include, exclude);
//         }
        
//         dp2[1] = nums[1];
//         for(int i=2; i<n; i++){
//             int include = nums[i];
//             if(i > 2) include += dp2[i-2];
//             int exclude = dp2[i-1];
//             dp2[i] = max(include, exclude);
//         }
//         return max(dp1[n-2], dp2[n-1]);
        int prev1 = nums[0];
        int prev2 = 0;
        for(int i=1; i<n-1;i++){
            int include = nums[i];
            if(i > 1) include += prev2;
            int exclude = prev1 + 0;
            int curr = max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        int prev3 = nums[1];
        int prev4 = 0;
        for(int i=2; i<n; i++){
            int include = nums[i];
            if(i > 2) include += prev4;
            int exclude = prev3;
            int curr = max(include, exclude);
            prev4 = prev3;
            prev3 = curr;
        }
        return max(prev1, prev3);
    }
};