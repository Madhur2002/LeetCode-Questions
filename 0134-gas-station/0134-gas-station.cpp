class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
//         for(int i=0; i<n; i++){
//             if(gas[i] < cost[i]) continue;
            
//             int j = (i+1)%n;
            
//             int currGas = gas[i] - cost[i] + gas[j];
//             while(j != i){
//                 if(currGas < cost[j]) break;
                
//                 int _cost = cost[j];
//                 j = (j+1)%n;
//                 int _gas = gas[j];
//                 currGas = currGas - _cost + _gas;
//             }
//             if(j == i) return i;
//         }
//         return -1;
        int totalKharcha = 0;
        int totalKamai = 0;
        for(int i=0; i<n; i++){
            totalKharcha += cost[i];
            totalKamai += gas[i];
        }
        if(totalKharcha > totalKamai) return -1;
        int totalKamaiAtStationi = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            totalKamaiAtStationi = totalKamaiAtStationi + gas[i] - cost[i];
            if(totalKamaiAtStationi < 0){
                totalKamaiAtStationi = 0;
                ans = i+1;
            }
        }
        return ans;
    }
        
};