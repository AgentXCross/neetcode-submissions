class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int i = digits.size() - 1;

        while (i >= 0 && digits[i] == 9) {
            digits[i] = 0;
            i--;
        }
        if (i < 0) {
            vector<int> extra_one = {1};
            extra_one.insert(extra_one.end(), digits.begin(), digits.end());
            return extra_one;
        }

        digits[i]++;

        return digits;
    }
};
