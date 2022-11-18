class Solution {
private:
    int findNegetiveNum(vector<int>& a){
        if(a[0] < 0) return a.size();
        if(a[a.size() - 1] >= 0) return 0;
        int low = 0;
        int high = a.size() - 1;
        int index = 0;
        while(low<=high){
            int mid = (low+high)>>1;
            if(a[mid] < 0){
                index = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }         
        }
        return a.size() - index;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(vector<int>& result : grid){
            ans += findNegetiveNum(result);
        }
        return ans;
    }
};