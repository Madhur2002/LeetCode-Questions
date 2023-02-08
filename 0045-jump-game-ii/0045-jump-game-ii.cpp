class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        
        int maxIndex = 0, jumps = 0, nextJump = 0;

        for(int i=0; i<n; i++) {
            nextJump = max(nextJump, i+nums[i]);

            if(i == maxIndex) {
                jumps++;
                maxIndex = nextJump;
            }
            if(maxIndex >= n-1) break;
        }
        return jumps;
    }
};