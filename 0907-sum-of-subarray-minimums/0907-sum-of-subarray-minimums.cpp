typedef long long int lli;
const lli MOD = 1e9 + 7;
class Solution {
public:
   lli add(lli a, lli b){
      return (a % MOD + b % MOD) % MOD;
   }
   lli mul(lli a, lli b){
      return (a % MOD * b % MOD) % MOD;
   }
   int sumSubarrayMins(vector<int>& A) {
      stack <int> st;
      int n = A.size();
      vector <int> left(n, -1);
      vector <int> right(n, n);
      int ans = 0;
      for(int i = 0; i < n; i++){
         while(!st.empty() && A[st.top()] >= A[i]){
         st.pop();
      }
      if(!st.empty())left[i] = st.top();
         st.push(i);
      }
      while(!st.empty())st.pop();
      for(int i = n - 1; i >= 0; i--){
         while(!st.empty() && A[st.top()] > A[i]){
            st.pop();
         }
         if(!st.empty())right[i] = st.top();
            st.push(i);
      }
      for(int i = 0; i < n; i++){
         int leftBound = i - (left[i] + 1);
         int rightBound = (right[i] - 1) - i;
         int contri = 1 + leftBound + rightBound + (leftBound * rightBound);
         ans = add(ans, mul(contri, A[i]));
      }
      return ans;
   }
};