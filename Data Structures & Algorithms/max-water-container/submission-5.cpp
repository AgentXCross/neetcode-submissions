class Solution {
private:
    int area(
        std::size_t l_idx, 
        std::size_t r_idx, 
        std::vector<int> &heights
    ) {
        return static_cast<int>(r_idx - l_idx) 
                * std::min(heights[l_idx], heights[r_idx]);
    }
    
public:
    int maxArea(std::vector<int> &heights) {
        int max_area = 0;

        std::size_t l = 0; 
        std::size_t r = heights.size() - 1;

        while (l < r) {
            max_area = std::max(max_area, area(l, r, heights));

            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return max_area;
    }
};
