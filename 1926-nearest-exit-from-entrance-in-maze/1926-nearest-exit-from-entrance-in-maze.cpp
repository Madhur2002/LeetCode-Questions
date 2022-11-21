class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row_size = maze.size();
        int col_size = maze[0].size();
        
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});

        int level = 0;
        
        maze[entrance[0]][entrance[1]] = '+';
        int dr_row[4] = {1,-1,0,0};
        int dr_col[4] = {0,0,-1,1};

        while(!q.empty()){
            int size = q.size();
            level++;
            for(int i=0;i<size;i++){
                auto pos = q.front();
                q.pop();
                int row = pos.first;
                int col = pos.second;
                for(int j=0;j<4;j++){
                    int new_row = row + dr_row[j];
                    int new_col = col + dr_col[j];
                    if(new_col >= 0 && new_row >= 0 && new_col < col_size && new_row < row_size){
                        if(maze[new_row][new_col] == '+') continue;
                        if(new_col == 0 || new_row == 0 || new_col == col_size-1 || new_row == row_size-1){
                            return level;
                        }
                        q.push({new_row,new_col});
                        maze[new_row][new_col] = '+';
                    }
                    
                }
            }
        }
        return -1;
    }
};