// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int n = nums.size();
//         int j = -1;
//         int flips = 0, ans = 0;
//         for(int i=0; i<n; i++){
//             if(nums[i] == 0) flips++;
//             if(flips > k){
//                 while(flips > k){
//                     j++;
//                     if(nums[j] == 0) flips--;
//                 }
//             }
//             int len = i - j;
//             ans = max(ans, len);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int high=0; int low=0;
        int ans=0;
        int n=nums.size();
        int cnt=0;
        while(high<n){
            while(high<n && cnt<=k){
                if(nums[high]==0) cnt++;
                if(cnt<=k) {
                    ans=max(ans,high-low+1);
                }
                high++;
            }
            while(low<=high && cnt>k){
                if(nums[low]==0) cnt--;
                low++;
            }
        }
        return ans;
    }
};