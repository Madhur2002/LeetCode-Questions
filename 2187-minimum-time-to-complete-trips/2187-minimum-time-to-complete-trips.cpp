class Solution {
private:
    long long tripsCount(vector<int>& time, long long sec){
        long long count = 0;
        for(auto it:time){
            count += (sec/it);
        }
        return count;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 0;
        long long high = 1e14;
        long long ans = high;
        while(low<=high){
            // long long mid = (low+high)/2;
            long long mid = (low+high)>>1;
            if(tripsCount(time,mid)>=totalTrips){
                ans = mid;
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};