class Solution {
public:

    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>mp;
        set<int>s;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        for(auto x : mp){
            if(s.count(x.second) > 0){
                return false;
            }
            s.insert(x.second);
        }
        return true;
    }
};