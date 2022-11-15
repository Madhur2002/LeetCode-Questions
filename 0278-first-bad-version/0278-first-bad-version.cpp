// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int low = 1;
        long int high = n;
        long int result = n;
        while(low<=high){
            long int mid = (low+high)>>1;
            if(isBadVersion(mid)){
                result = mid;
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        return result;
    }
};