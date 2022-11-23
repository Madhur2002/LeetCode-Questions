class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int delta_row[], int delta_col[], int initialColor, int newColor){
        ans[row][col] = newColor;
        int row_size = image.size();
        int col_size = image[0].size();
        for(int i=0;i<4;i++){
            int new_row = row + delta_row[i];
            int new_col = col + delta_col[i];

            if(new_row >= 0 && new_row < row_size && new_col >= 0 && new_col < col_size && 
               image[new_row][new_col] == initialColor && ans[new_row][new_col] != newColor){
                   dfs(new_row, new_col, ans, image, delta_row, delta_col, initialColor, newColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        cout<<initialColor;
        int delta_row[] = {-1, 0, +1, 0};
        int delta_col[] = {0, +1, 0, -1}; 
        vector<vector<int>>ans = image;
        dfs(sr, sc, ans, image, delta_row, delta_col, initialColor, color);
        return ans;
    }
};