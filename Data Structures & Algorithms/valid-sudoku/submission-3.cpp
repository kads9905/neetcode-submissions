class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Each number 1–9 gets one bit. If that bit is already 1, we've seen that number before.
        // o(n2) o(n)
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                // converts the Sudoku character into a bit position.
                int val = board[r][c] - '1';

                // Create a bit corresponding to this number
                if ((rows[r] & (1 << val)) || (cols[c] & (1 << val)) ||
                    (squares[(r / 3) * 3 + (c / 3)] & (1 << val))) {
                    return false;
                }

                rows[r] |= (1 << val);
                cols[c] |= (1 << val);
                squares[(r / 3) * 3 + (c / 3)] |= (1 << val);
            }
        }
        return true;
    }
};