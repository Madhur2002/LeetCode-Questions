class Solution {
private:
    void solve(int ind, string nums, int dots, string ans, vector<string>& res, string& s){
        if(dots == 3){
            string r = s.substr(ind);
            
            if(r.size() == 0 || (r[0] == '0' && r.size() > 1)){
                return;
            }
            
            long temp = stol(r);
            if(temp <= 255){
                ans += r;
                res.push_back(ans);
            }
            
            return;
        }
        
        if(ind >= n || nums[0] == '0') return;
                
        nums += s[ind];
        long temp = stol(nums);
        if(temp <= 255){
            solve(ind+1, nums, dots, ans, res, s);
            ans = ans + nums + ".";
            solve(ind+1, "", dots+1, ans, res, s);
        }
    }
public:
    int n;
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        vector<string>res;
        solve(0, "", 0, "", res, s);
        return res;
    }
};