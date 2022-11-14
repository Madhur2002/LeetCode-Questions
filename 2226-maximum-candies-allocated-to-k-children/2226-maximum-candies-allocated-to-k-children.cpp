class Solution {
private:
    bool children_count(int mid, long long k, vector<int>& candies){
        if(mid == 0){
            return true;
        }
        long long count = 0;
        for(auto candy : candies){
            count += candy/mid;
            // cout<<"count"<<count<<" ";
            if(count>=k){
                return true;
            }
        }
        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int max_element = candies[0];
        for(int i=0;i<candies.size();i++){
            if(max_element < candies[i]){
                max_element = candies[i];
            }
        }
        int i=1;
        int j = max_element;
        while(i<j){
            // cout<<"i:"<<i<<" "<<"j:"<<j<<" ";
            int mid = (i+j)>>1;
            // cout<<mid<<" ";
            if(children_count(mid, k, candies)){
                i = mid+1;
            }else{
                j = mid;
            }
        }
        return children_count(i, k, candies) ? i : i-1;
    }
};