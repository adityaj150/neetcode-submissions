class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 1st condition for checking rows repetition
        for (int i = 0; i < board.size(); i++) {
            unordered_set<char> seen;
            for (int j = 0; j < board[i].size(); j++) {
                char num = board[i][j];
                if (num != '.') {
                    if (seen.find(num) != seen.end()) { // this number is already in the row
                        return false;
                    }
                    seen.insert(num);
                }
            }
        }

        // 2nd condition is to check repetition of numbers in the column
        for (int j = 0; j < board[0].size(); j++) {
            unordered_set<char> seen2;
            for (int i = 0; i < board.size(); i++) {
                char num = board[i][j];
                if (num != '.') {
                    if (seen2.find(num) != seen2.end()) {
                        return false;
                    }
                    seen2.insert(num);
                }
            }
        }

        // 3rd condition is to check if there is repetition of numbers in the subgrid
        vector<unordered_set<char>> subgrids(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num != '.') {
                    int subgridIndex = (i / 3) * 3 + (j / 3); 
                    if (subgrids[subgridIndex].find(num) != subgrids[subgridIndex].end()) {
                        return false;
                    }
                    subgrids[subgridIndex].insert(num);
                }
            }
        }

        return true;
    }
};
