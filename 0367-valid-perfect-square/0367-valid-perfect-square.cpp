class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i=0;
        long long j = num;
        if(num == 1) return true;
        while(i<j){
            long long mid = (i+j)>>1;
            if(mid == i||mid==j){
                break;
            }
            long long sqr = mid*mid;
            if(sqr == num){
                return true;
            }else if(sqr > num){
                j=mid;
            }else{
                i=mid;
            }
        }
        return false;
    }
};