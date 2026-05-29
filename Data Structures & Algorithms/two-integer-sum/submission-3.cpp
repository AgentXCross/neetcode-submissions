class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> seen;
        int idx = 0;
        for (const int &num : nums) {
            int looking_for = target - num;
            if (seen.find(looking_for) != seen.end()) {
                return vector<int>{seen[looking_for], idx};
            }
            seen[num] = idx;
            idx++;
        }
    }
};
