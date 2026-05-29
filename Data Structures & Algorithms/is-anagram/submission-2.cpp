class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_freq;
        unordered_map<char, int> t_freq;

        if (s.length() != t.length()) {
            return false;
        }

        for (char &s_char : s) {
            if (s_freq.find(s_char) == s_freq.end()) {
                s_freq[s_char] = 0;
            } else {
                s_freq[s_char]++;
            }
        }

        for (char &t_char : t) {
            if (t_freq.find(t_char) == t_freq.end()) {
                t_freq[t_char] = 0;
            } else {
                t_freq[t_char]++;
            }
        }

        return s_freq == t_freq;
    }
};
