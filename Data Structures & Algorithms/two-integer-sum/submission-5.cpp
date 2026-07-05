class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int looking_for = target - nums[i];

            if (seen.find(looking_for) != seen.end()) {
                return {seen[looking_for], i};
            }

            seen[nums[i]] = i;
        }
    }
};
