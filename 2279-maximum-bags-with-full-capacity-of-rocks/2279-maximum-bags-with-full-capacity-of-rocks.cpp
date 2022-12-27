class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        vector<int>required(n, 0);
        for(int i=0; i<n; i++){
            required[i] = capacity[i] - rocks[i];
        }
        sort(required.begin(), required.end());
        int count = 0;
        for(auto x: required){
           if(x == 0) count++;
           else{
               if(additionalRocks >= x) {
                   additionalRocks -= x;
                   count++;
               }else{
                   break;
               }
           }
        }
        return count;
    }
};