class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(target!=nums[0]){
                return -1;
            }
            return 0;
        }
        // sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size() - 1;
        while(low<=high){
            int mid = (low+high)>>1;
            if(nums[mid] == target){
                return mid;
            }else if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target <= nums[mid]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }else{ 
                if(target >= nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};