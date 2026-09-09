class Solution {
public:
    vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> seen;

        for (std::size_t i = 0; i < nums.size(); i++) {
            int looking_for = target - nums[i];

            if (seen.find(looking_for) != seen.end()) {
                return {seen[looking_for], static_cast<int>(i)};
            }

            seen[nums[i]] = i;
        }
    }
};
