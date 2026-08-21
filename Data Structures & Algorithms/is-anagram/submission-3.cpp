class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_freq;
        unordered_map<char, int> t_freq;

        for (char& c : s) {
            if (s_freq.find(c) == s_freq.end()) {
                s_freq[c] = 0;
            } else {
                s_freq[c]++;
            }
        }

        for (char& c : t) {
            if (t_freq.find(c) == t_freq.end()) {
                t_freq[c] = 0;
            } else {
                t_freq[c]++;
            }
        }

        return s_freq == t_freq;
    }
};
