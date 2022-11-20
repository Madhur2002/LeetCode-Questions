class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(),nums2.end());
        int low = 0;
        int high = nums2.size()-1;
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            int target = nums1[i];
            cout<<target;
            low = 0;
            high = nums2.size()-1;
            // cout<<target<<" ";
            while(low<=high){
                int mid = (low+high)>>1;
                if(nums2[mid] == target){
                    ans.push_back(nums2[mid]);
                    nums2.erase(nums2.begin()+mid);
                    break;
                }else if(nums2[mid]>target){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
        }
        return ans;
    }
};