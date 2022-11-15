class Solution {
public:
    // vector<int> searchRange(vector<int>& arr, int target) {
    //     long int low = 0;
    //     long int high = arr.size() - 1;
    //     vector<int>ans;
    //     long int min_index = -1;
    //     long int max_index = -1;
    //     if(arr.size() == 1 && arr[0] == target){
    //         ans.push_back(0);
    //         ans.push_back(0);
    //         return ans;
    //     }
    //     if(arr.size() == 2 && arr[1] == target && arr[0] != target){
    //         ans.push_back(1);
    //         ans.push_back(1);
    //         return ans;
    //     }
    //     if(arr.size() == 2 && arr[0] == target && arr[1] == target){
    //         ans.push_back(0);
    //         ans.push_back(1);
    //         return ans;
    //     }
    //     while(low<high){
    //         long int mid = (low+high)>>1;
    //         if(arr[low] == arr[high] && arr[low] == target){
    //             min_index = low;
    //             max_index = high;
    //             break;
    //         }
    //         if(arr[mid] == target){
    //             if((mid-1) >= 0 && (mid+1) <=arr.size()-1 && arr[mid] == arr[mid-1] && arr[mid] != arr[mid+1]){
    //                 min_index = mid-1;
    //                 max_index = mid;
    //                 low = 0;
    //                 high = mid;
    //             }
    //             else if((mid-1) >= 0 && (mid+1) <=arr.size()-1 && arr[mid] == arr[mid+1] && arr[mid] != arr[mid-1]){
    //                 min_index = mid;
    //                 max_index = mid+1;
    //                 high = arr.size()-1;
    //                 low = mid;
    //             }
    //             else if((mid-1) >= 0 && (mid+1) <=arr.size()-1 && arr[mid] == arr[mid+1] && arr[mid] == arr[mid-1]){
    //                 min_index = mid-1;
    //                 max_index = mid+1;
    //                 low = mid-2;
    //                 high = mid+2;
    //             }
    //             else{
    //                 min_index = mid;
    //                 max_index = mid;
    //                 break;
    //             }
    //         }else if(arr[mid] < target){
    //             low = mid+1;
    //         }else{
    //             high = mid;
    //         }
    //     }
    //     ans.push_back(min_index);
    //     ans.push_back(max_index);
    //     return ans;
    // }
    vector<int> searchRange(vector<int>& N, int T) {
        int Tleft = find(T, N);
        if (Tleft == N.size() || N[Tleft] != T) return {-1, -1};
        return {Tleft, find(T+1, N, Tleft) - 1};
    }
    int find(int target, vector<int> arr, int left=0) {
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + right >> 1;
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};