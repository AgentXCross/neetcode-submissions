class Solution {
public:
    int singleNumber(std::vector<int> &nums) {
        int once = nums[0];

        for (std::size_t i = 1; i < nums.size(); ++i) {
            once ^= nums[i];
        }

        return once;
    }
};
