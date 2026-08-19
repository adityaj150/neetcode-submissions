class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // for row wise
        for(int i = 0; i < board.size(); i++){
            unordered_set<char>seen;
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(seen.find(board[i][j]) != seen.end()){
                    return false;
                }
                seen.insert(board[i][j]);
            }
        }

        // for column wise
        for(int i = 0; i < board.size(); i++){
            unordered_set<char>seen1;
            for(int j = 0; j < board[i].size(); j++){
                if(board[j][i] == '.'){
                    continue;
                }
                if(seen1.find(board[j][i]) != seen1.end()){
                    return false;
                }
                seen1.insert(board[j][i]);
            }
        }

        // for square wise
        for(int i = 0; i < 9; i++){
            unordered_set<char>seen3;
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    int row = (i / 3) * 3 + j;
                    int col = (i % 3) * 3 + k;
                    if(board[row][col] == '.') continue;
                    if(seen3.count(board[row][col])) return false;
                    seen3.insert(board[row][col]);
                }
            }
        }

        return true;
    }
};
