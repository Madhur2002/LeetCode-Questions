class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low<=high){
            int mid = (low+high)>>1;
            if(target>nums[high]){
                return high+1;
            }
            if(nums[mid] == target || low == high){
                return mid;
            }
            else if(nums[mid] > target){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return -1;
    }
};