class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }

        unordered_set<int> nums_set;
        for (int &num : nums) {
            nums_set.insert(num);
        }

        int longest_sequence = 1;
        for (int &num : nums) {
            if (nums_set.find(num - 1) != nums_set.end()) {
                // if one less is in, then skip
                continue;
            } 
            int current_length = 1;
            int n = num;
            while (nums_set.find(n + 1) != nums_set.end()) {
                current_length++;
                n++;
            }
            if (current_length > longest_sequence) {
                longest_sequence = current_length;
            }
        }

        return longest_sequence;
    }
};
