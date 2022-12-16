class Solution {
private:
    int dp(vector<int>& cost, vector<int>& arr, int ind){
        if(ind >= cost.size()){
            return 0;
        }
        if(arr[ind] != -1) return arr[ind];
        int one_step = cost[ind] + dp(cost, arr, ind+1);
        int two_step = cost[ind] + dp(cost, arr, ind+2);
        arr[ind] = min(one_step, two_step);
        return arr[ind];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> arr(n+1, -1);
        return min(dp(cost, arr, 0), dp(cost, arr, 1));
    }
};