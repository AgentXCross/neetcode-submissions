class Solution {
public:
    int trap(vector<int> &height) {
        vector<int> max_left(height.size());
        vector<int> max_right(height.size()); 

        int curmax_left = 0;
        for (int i = 0; i < height.size(); i++) {
            max_left[i] = curmax_left;
            curmax_left = max(curmax_left, height[i]);
        }

        int curmax_right = 0;
        for (int j = height.size() - 1; j >= 0; j--) {
            max_right[j] = curmax_right;
            curmax_right = max(curmax_right, height[j]);
        }

        int max_water = 0;
        for (int k = 0; k < height.size(); k++) {
            max_water += max(0, min(max_right[k], max_left[k]) - height[k]);
        }

        return max_water;
    }
};
