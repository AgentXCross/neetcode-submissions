#include <climits>

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int max_so_far = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int sum_from_i = 0;
            for (int j = i; j < nums.size(); j++) {
                sum_from_i += nums[j];
                if (sum_from_i > max_so_far) {
                    max_so_far = sum_from_i;
                }
            }
        }
        return max_so_far;
    }
};
