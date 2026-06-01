class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq;

        for (int &num : nums) {
            if (num_freq.find(num) == num_freq.end()) {
                num_freq[num] = 1;
            } else {
                num_freq[num]++;
            }
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (const auto &[key, value] : num_freq) {
            buckets[value].push_back(key);
        }

        vector<int> results;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int num : buckets[i]) {
                results.push_back(num);
                k--;

                if (k == 0) {
                    return results;
                }
            }
        }

    }
};
