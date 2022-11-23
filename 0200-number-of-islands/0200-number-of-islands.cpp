class Solution {
//   private: 
//   void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>&grid) {
//       // mark it visited
//       vis[row][col] = 1; 
//       queue<pair<int,int>> q;
//       // push the node in queue
//       q.push({row, col}); 
//       int n = grid.size(); 
//       int m = grid[0].size(); 
      
//       // until the queue becomes empty
//       while(!q.empty()) {
//           int row = q.front().first; 
//           int col = q.front().second; 
//           q.pop(); 
          
//           // traverse in the neighbours and mark them if its a land 
//           for(int delrow = -1; delrow<=1;delrow++) {
//               for(int delcol = -1; delcol <= 1; delcol++) {
//                   int nrow = row + delrow; 
//                   int ncol = col + delcol; 
//                   // neighbour row and column is valid, and is an unvisited land
//                   if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
//                   && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
//                       vis[nrow][ncol] = 1; 
//                       q.push({nrow, ncol}); 
//                   }
//               }
//           }
//       }
//   }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};