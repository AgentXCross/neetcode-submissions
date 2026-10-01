class Solution {
private:
    int rows{0};
    int cols{0};

    std::pair<int, int> flatTo2dIndex(
        int index
    ) {
        int row{index / cols};
        int col{index % cols};

        return {row, col};
    }

public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    int l{0};

    int rows_num{static_cast<int>(matrix.size())};
    int cols_num{static_cast<int>(matrix[0].size())};

    rows = rows_num;
    cols = cols_num;

   int r{rows * cols - 1};

    while (l <= r) {
        int middle{(l + r) / 2};

        auto [row, col] = flatTo2dIndex(middle);

        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            l = middle + 1;
        } else {
            r = middle - 1;
        }
    }

    return false;
        
    }
};
