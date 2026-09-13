class Solution {
public:
    std::vector<int> topKFrequent(
        std::vector<int> &nums, 
        int k
    ) {
        std::unordered_map<int, int> num_freq;

        for (int &num : nums) {
            if (num_freq.find(num) == num_freq.end()) {
                num_freq[num] = 0;
            } 

            num_freq[num]++;
        }

        std::vector<std::vector<int>> freq_to_nums(nums.size() + 1);

        std::vector<int> return_vector;

        for (const auto &[num, freq] : num_freq) {
            freq_to_nums[freq].push_back(num);
        }

        for (int i = freq_to_nums.size() - 1; i >= 0; i--) {
            for (int j = 0; j < freq_to_nums[i].size(); j++) {
                return_vector.push_back(freq_to_nums[i][j]);
                
                if (return_vector.size() == k) {
                    return return_vector;
                }
            }
        }

        return return_vector;
    }
};
