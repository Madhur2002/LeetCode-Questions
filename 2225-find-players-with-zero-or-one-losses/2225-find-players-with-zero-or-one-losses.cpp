class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int>s;
        
        vector<int>exactly_one_loss;
        vector<vector<int>>ans;
        unordered_map<int, int>mp;
        int n = matches.size();
        for(int i=0; i<n; i++){
            mp[matches[i][1]]++;
        }
        for(int i=0; i<n; i++){
            if(mp.find(matches[i][0]) == mp.end() ){
                s.insert(matches[i][0]);
            }
            if(mp[matches[i][1]] == 1){
                exactly_one_loss.push_back(matches[i][1]);
            }
        }
        // sort(zero_loss.begin(), zero_loss.end());
        sort(exactly_one_loss.begin(), exactly_one_loss.end());
        vector<int>zero_loss(s.begin(), s.end());
        sort(zero_loss.begin(), zero_loss.end());
        ans.push_back(zero_loss);
        ans.push_back(exactly_one_loss);
        return ans;
    }
};