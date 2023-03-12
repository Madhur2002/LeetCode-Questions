class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if(a[1] == b[1]) return a[0] < b[0];
        
        return b[1] > a[1];
    }
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        sort(tasks.begin(), tasks.end(), cmp); // soritng based on end time
        vector<int> on(2001);
        
        for(auto& task: tasks) {
            int s = task[0], e = task[1], dur = task[2];
            for(int i=s; i<=e; i++) 
                if(on[i] == 1) 
                    dur--;
            
            for(int i=e; dur>0; i--) {
                if(on[i] == 1) 
                    continue;
                else{
                    on[i] = 1;
                    dur--;
                }
            }
        }
        
        int onTime = 0;
        for(int i=0; i<on.size(); i++) {
            if(on[i] == 1) onTime++;
        }
        return onTime;
    }
};