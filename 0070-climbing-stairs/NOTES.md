class Solution {
public:
int solve(int n , vector<int> &dp)
{
if(n <= 2) return n;
if(dp[n]!=-1) return dp[n];
return dp[n] = solve(n-1,dp) + solve(n-2,dp);
}
int climbStairs(int n) {
vector<int> dp(n+1,-1);
return solve(n,dp);
}
solution 2:
int climbStairs(int n) {
vector<int>v(n+1, -1);
v[0] = 0;
v[1] = 1;
if(n >= 2) v[2] = 2;
for(int i=3; i<=n; i++){
v[i] = v[i-1] + v[i-2];
}
return v[n];
}
O(n) and O(1) solution:
​
​
};