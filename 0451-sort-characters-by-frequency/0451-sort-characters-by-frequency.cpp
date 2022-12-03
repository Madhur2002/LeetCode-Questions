class Solution {
 public:
    static bool cmp(pair<char, int>& a, pair<char, int>& b){
        return b.second < a.second;
    }
    string frequencySort(string s) {
        string str;
        map<char, int>mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        
        vector<pair<char, int>>v;
        for(auto it : mp){
            v.push_back(it);
        }
        sort(v.begin(), v.end(), cmp);
        string ans = "";
        for(auto it : v){
            char c = it.first;
            int n = it.second;
            while(n--){
                ans += c;
            }
        }
        return ans;


        
    }
};