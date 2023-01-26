class Solution {
private:
    int solve(vector<int>& nums, int k){
        int i = 0;
        int j = 0;
        int count = 0;
        unordered_map<int, int>mp;
        while(j < nums.size()){
            mp[nums[j]]++;
            if(mp.size() > k){
                while(mp.size() > k){
                    int freq = mp[nums[i]];
                    if(freq == 1) mp.erase(nums[i]);
                    else mp[nums[i]]--;
                    i++;
                }
            }
            count += (j-i+1);
            j++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a = solve(nums, k);
        int b = solve(nums,  k-1);
        return a-b;
    }
};