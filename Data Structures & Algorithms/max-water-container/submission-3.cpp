class Solution {
private:
    int area(int l, int r, int height_l, int height_r) {
        return (r - l) * min(height_l, height_r);
    }
public:
    int maxArea(vector<int> &heights) {
        int max_area = 0;

        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int cur_area = area(left, right, heights[left], heights[right]);
            if (cur_area > max_area) {
                max_area = cur_area;
            }

            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
        }
        return max_area;
    }
};
