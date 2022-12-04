// class Solution {
// private:
//     long long avg(vector<int>& nums, int i){
//         if(nums.size() == 0){
//            return 0;
//         }
//         // return accumulate(nums.begin(), i, 0)/i+1;
//         long long sum = 0;
//         auto it = nums.begin();
//         while(it <= nums.begin() + i){
//             sum += *it;
//             it++;
//         }
//         return sum/(i+1);
//     }
    
//     long long avg2(vector<int>& nums, int i){
//         if(i == nums.size() - 1){
//             return 0;
//         }
//         if(nums.size() == 0){
//             return 0;
//         }
//         long long n = (nums.size() - 1) - i;
//         long long sum = 0;
//         // return accumulate(nums.begin() + i, nums.end(), 0)/(n - i);
//         auto it = nums.begin()+(i+1);
//         while(it != nums.end()){
//             sum += *it;
//             it = it + 1;
//         }
//         return sum/n;
//     } 
// public:
//     int minimumAverageDifference(vector<int>& nums) {
//         vector<pair<int, int>>v;
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             long long x = avg(nums, i);
//             long long y = avg2(nums, i);
//             int ans = abs(x-y);
//             v.push_back({i, ans});
//         }
//         int minAvgDiffIndx = 0;
//         int minAvgDiff = INT_MAX;
//         for(auto it : v){
//             int a = it.first;
//             int b = it.second;
//             if(b < minAvgDiff){
//                 minAvgDiff = b;
//                 minAvgDiffIndx = a;
//             }
//         }
//         return minAvgDiffIndx;
//     }
// };
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        
        //Total Sum
        long long sum = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
        }
        
        long long LS = 0;
        long long RS = 0;
        
        int result = INT_MAX;
        int idx    = -1;
        
        for(int i = 0; i<n; i++) {
            LS += nums[i]; //nikalte chalenge
            RS  = sum-LS; //LS+RS = sum
            
            int n1 = i+1;
            int n2  = n-n1; //n1+n2 = n
            
            long long left_avg  = LS/n1;
            long long right_avg = (i==n-1) ? 0 : RS/n2;
            
            int diff = abs(left_avg - right_avg);
            
            if(result > diff) {
                result = diff;
                idx = i;
            }
        }
        
        return idx;
    }
};