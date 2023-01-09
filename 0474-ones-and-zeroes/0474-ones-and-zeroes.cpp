class Solution {
// private:
//     int solve(vector<vector<vector<int>>>dp, vector<string>& strs, int m, int n, int ind){
//         if(ind == 0){
//             int count_ones = count(strs[0].begin(), strs[0].end(), '1');
//             int count_zeros = strs[0].size() - count_ones;
//             if(m-count_zeros >= 0 && n-count_ones >= 0) return 1;
//             else return 0;
//         }
//         if(dp[m][n][ind] != -1) return dp[m][n][ind];
//         int count_ones = count(strs[ind].begin(), strs[ind].end(), '1');
//         int count_zeros = strs[ind].size() - count_ones;
        
//         int not_take = solve(dp, strs, m, n, ind-1);
//         int take = 0;
//         if(m-count_zeros >= 0 && n-count_ones >= 0){
//             take = 1 + solve(dp, strs, m-count_zeros, n-count_ones, ind-1);
//         }
//         return dp[m][n][ind] = max(take, not_take);
//     }
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         int size = strs.size();
//         vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(size, -1)));
//         return solve(dp, strs, m, n, size-1);
//     }
    vector<vector<vector<int>>>dp;
    public:
    int findMaxForm(vector<string>& strs, int m, int n) {
          
          dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
           return findmax(strs,m,n,0);
        
        
    }
    
     int findmax (vector<string>& strs, int m, int n,int index)
     {
         if(index==strs.size())return 0;
         if(dp[m][n][index]!=-1)return dp[m][n][index];
         int countzeroes = count(strs[index].begin(),strs[index].end(),'0');
         int countones = strs[index].size()-countzeroes;
         
         if(m-countzeroes>=0 && n-countones>=0)
         return dp[m][n][index]= max(1+findmax(strs,m-countzeroes,n-countones,index+1),
         findmax(strs,m,n,index+1));
         
         return dp[m][n][index]=findmax(strs,m,n,index+1);
     }
};