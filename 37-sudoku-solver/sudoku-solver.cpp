class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig) {
                return false;
            }
        }
        
        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig) {
                return false;
            }
        }
        
        // Check 3x3 box
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;
        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] == dig) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool helper(vector<vector<char>>& board, int r, int c) {
        // Base case: reached end of board
        if (r == 9) {
            return true;
        }
        
        // Calculate next cell
        int nextrow = r;
        int nextcol = c + 1;
        if (nextcol == 9) {
            nextrow = r + 1;
            nextcol = 0;
        }
        
        // If cell is already filled, move to next
        if (board[r][c] != '.') {
            return helper(board, nextrow, nextcol);  // ✅ Fixed
        }
        
        // Try digits 1-9
        for (char dig = '1'; dig <= '9'; dig++) {  // ✅ Fixed (<=)
            if (isSafe(board, r, c, dig)) {
                board[r][c] = dig;
                if (helper(board, nextrow, nextcol)) {
                    return true;
                }
                board[r][c] = '.';  // ✅ Backtrack
            }
        }
        
        return false;  // ✅ No solution from this state
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};