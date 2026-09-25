class Solution {
public:
    std::vector<std::vector<int>> threeSum(
        std::vector<int> &nums) 
    {
        std::vector<std::vector<int>> triplets;
        std::set<std::vector<int>> seen;

        std::sort(nums.begin(), nums.end());

        for (std::size_t i = 0; i < nums.size(); ++i) {
            int looking_for = -nums[i];

            std::size_t l = i + 1;
            std::size_t r = nums.size() - 1;

            while (l < r) {
                if (nums[l] + nums[r] == looking_for) {
                    if (seen.find({nums[i], nums[l], nums[r]}) == seen.end()) {
                        triplets.push_back({nums[i], nums[l], nums[r]});
                    } 
                    seen.insert({nums[i], nums[l], nums[r]});

                    ++l;
                    --r;
                } else if (nums[l] + nums[r] < looking_for) {
                    ++l;
                } else {
                    --r;
                }
            }
        }

        return triplets;
    }
};
