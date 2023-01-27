class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        int j = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                j = i;
                continue;
            }
            int len = i-j;
            maxlen = max(len, maxlen);
        }
        return maxlen;
    }
};