class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, std::size_t> s_freq;
        std::unordered_map<char, std::size_t> t_freq;

        if (s.length() != t.length()) {
            return false;
        }

        for (std::size_t i = 0; i < s.length(); i++) {
            if (s_freq.find(s[i]) == s_freq.end()) {
                s_freq[s[i]] = 0;
            } else {
                s_freq[s[i]]++;
            }

            if (t_freq.find(t[i]) == t_freq.end()) {
                t_freq[t[i]] = 0;
            } else {
                t_freq[t[i]]++;
            }
        }

        return s_freq == t_freq;
    }
};
