class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;
        int j = arr.size() - 1;
        int mid = 0,ans = -1;
        while(i<j){
            int mid = (i+j)>>1;
            if(arr[mid] > arr[mid+1]){
                ans = mid;
                j = mid;
            }
            else{
                ans = mid+1;
                i = mid+1;
            }
                
        }
        return ans;
    
    }
};