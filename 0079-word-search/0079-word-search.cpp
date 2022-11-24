class Solution {
private:
    bool find(int row, int col, vector<vector<char>>& board, string word, int index){
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        if(index == word.length()){
            return true;
        }
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '$'){
            return false;
        }
        if(board[row][col] != word[index]){
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '$';
        
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(find(nrow, ncol, board, word, index+1)){
                return true;
            }
        }
        board[row][col] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0] && find(i, j, board, word, 0))
                    return true;
            }
        }
        return false;
    }
};