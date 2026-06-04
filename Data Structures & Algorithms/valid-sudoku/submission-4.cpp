class Solution {
    private:
        bool isValidRow(vector<char> &row) {
            unordered_set<char> seen;
            for (char &c : row) {
                if (c == '.') {
                    continue;
                }
                if (seen.find(c) != seen.end()) {
                    return false;
                } else {
                    seen.insert(c);
                }
            }
            return true;
        }

        vector<vector<char>> transpose(vector<vector<char>> &board) {
            vector<vector<char>> transposed_board(9, vector<char>(9));
            for (int i = 0; i < 9; i++) {
                vector<char> row;
                for (int j = 0; j < 9; j++) {
                    row.push_back(board[j][i]);
                }
                transposed_board[i] = row;
            }
            return transposed_board;
        }

        vector<vector<char>> get_boxes(vector<vector<char>> &board) {
            vector<vector<char>> boxes_board(9, vector<char>(9));
            vector<pair<int, int>> t_l = {
                {0, 0}, {0, 3}, {0, 6},
                {3, 0}, {3, 3}, {3, 6},
                {6, 0}, {6, 3}, {6, 6}
            };
            vector<pair<int, int>> b_r = {
                {2, 2}, {2, 5}, {2, 8},
                {5, 2}, {5, 5}, {5, 8},
                {8, 2}, {8, 5}, {8, 8}
            };
            for (int i = 0; i < 9; i++) {
                auto &top_left = t_l[i];
                auto &bottom_right = b_r[i];
                vector<char> box;
                for (int j = top_left.first; j <= bottom_right.first; j++) {
                    for (int k = top_left.second; k <= bottom_right.second; k++) {
                        box.push_back(board[j][k]);
                    }
                }
                boxes_board[i] = box;
            }
            return boxes_board;
        }
    public:
        bool isValidSudoku(vector<vector<char>> &board) {
            // Check rows
            for (vector<char> &row : board) {
                if (!isValidRow(row)) {
                    return false;
                }
            }
            // Check columns
            vector<vector<char>> transposed = transpose(board);
            for (vector<char> &row : transposed) {
                if (!isValidRow(row)) {
                    return false;
                }
            }

            // Check boxes
            vector<vector<char>> boxes = get_boxes(board);
            for (vector<char> &box : boxes) {
                if (!isValidRow(box)) {
                    return false;
                }
            }
            return true;
        }
};
