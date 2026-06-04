class Solution {
private:
    pair<int, int> convert_idx_to_2D(int index, int width) {
        int row = index / width;
        int col = index - row * width;

        return {row, col};
    }

    int convert_2D_to_idx(pair<int, int> coord, int width) {
        return coord.first * width + coord.second;
    }
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int height = matrix.size();
        int width = matrix[0].size();
        
        int left = 0;
        int right = width * height - 1;

        while (left <= right) {
            int middle = (left + right) / 2;

            pair<int, int> middle_coords = convert_idx_to_2D(middle, width);
            int middle_val = matrix[middle_coords.first][middle_coords.second];

            if (middle_val == target) {
                return true;
            } else if (middle_val < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return false;
    }
};
