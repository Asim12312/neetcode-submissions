class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Rows
        vector<vector<bool>> row(9, vector<bool>(9, false));

        // Columns
        vector<vector<bool>> col(9, vector<bool>(9, false));

        // 3x3 Boxes
        vector<vector<vector<bool>>> box(
            3, vector<vector<bool>>(3, vector<bool>(9, false))
        );

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                char c = board[i][j];

                // Skip empty cells
                if (c == '.') {
                    continue;
                }

                // Convert '1'-'9' to index 0-8
                int num = c - '1';

                // Check row, column, and 3x3 box
                if (row[i][num] ||
                    col[j][num] ||
                    box[i / 3][j / 3][num]) {
                    return false;
                }

                // Mark as seen
                row[i][num] = true;
                col[j][num] = true;
                box[i / 3][j / 3][num] = true;
            }
        }

        return true;
    }
};