class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>p;
        int sum = 0;
        for(int i=0; i<piles.size(); i++){
            sum += piles[i];
            p.push(piles[i]);
        }
        while(k != 0){
            int a = p.top();
            p.pop();
            int remove = floor(a/2);
            sum -= remove;
            a -= remove;
            p.push(a);
            k--;
        }
        return sum;
    }
};