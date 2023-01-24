class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int m = board[0].size(), target = pow(m, 2);
        reverse(board.begin(), board.end());
        
        for(int i=0; i<m; i++){
            if(i % 2) reverse(board[i].begin(), board[i].end());
        }
        
        queue<int>q;
        vector<int>vis(target+1, 0);
        q.push(1);
        int steps = 0;
        
        while(!q.empty()){
            steps++;
            int s = q.size();
            for(int k=0; k<s; k++){
                int front = q.front();
                q.pop();
                for(int i=1; i<=6; i++){
                    int next_pos = front + i;
                    if(next_pos > target) continue;
                    
                    int row = (next_pos-1)/m;
                    int col = (next_pos-1)%m;
                    
                    if(board[row][col] != -1 && board[row][col] != next_pos){
                        next_pos = board[row][col];
                    }
                    if(vis[next_pos]) continue;
                    
                    if(next_pos == target) return steps;
                    vis[next_pos] = 1;
                    q.push(next_pos);
                }
            }
        }
        return -1;
        
    }
};