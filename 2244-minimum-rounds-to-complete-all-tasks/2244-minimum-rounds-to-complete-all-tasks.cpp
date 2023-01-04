class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int>mp;
        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        }
        int tcount = 0;
        for(auto it: mp){
            if(it.second == 1){
                return -1;
            }
            int count = 0;
            while(it.second > 3){
                it.second -= 3;
                count++;
            }
            if(it.second) count++;
            tcount += count;
        }
        return tcount;
    }
};