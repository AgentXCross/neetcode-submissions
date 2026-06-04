class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int s_len = s.length();

        int longest_so_far = 0;
        int substr_start = 0;
        unordered_set<char> cur_substr;

        for (int i = 0; i < s_len; i++) {
            if (cur_substr.find(s[i]) != cur_substr.end()) {
                while (s[substr_start] != s[i]) {
                    cur_substr.erase(s[substr_start]);
                    substr_start++;
                }
                substr_start++;
            } else {
                cur_substr.insert(s[i]);
                if (cur_substr.size() > longest_so_far) {
                    longest_so_far = cur_substr.size();
                }
            }
        }
        return longest_so_far;
    }
};
