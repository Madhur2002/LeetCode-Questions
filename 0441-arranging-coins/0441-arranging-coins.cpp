class Solution {
public:
    int arrangeCoins(int n) {
        long low = 1;
        long high = n;
        while(low<=high){
            long mid = (low+high)>>1;
            if(n >= (mid*(mid+1))>>1){
                low = mid + 1;
            }else{
                high = mid-1;
            }
        }
        return (int)low-1;
    }
};