class Solution {
private:
    int binarySearch(vector<int>& nums2, int index, int target){
        int low = index;
        int high = nums2.size() - 1;
        int ans = -1;
        while(low<=high){
            int mid = (low+high)>>1;
            if(nums2[mid] >= target){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;  
            }
        }
        return ans;
    }
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxValue = 0;
        for(int i=0;i<nums1.size();i++){
            int ans = binarySearch(nums2,i,nums1[i]);
            
            if(ans != -1){
                maxValue = max(ans-i,maxValue);
            }
        }
        return maxValue;
    }
};