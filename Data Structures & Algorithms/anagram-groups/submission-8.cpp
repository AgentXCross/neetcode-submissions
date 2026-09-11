class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(
        std::vector<std::string> &strs
    ) {
        std::vector<std::vector<std::string>> return_vector;

        std::unordered_map<string, std::vector<std::string>> anagrams;

        for (std::string &str : strs) {
            std::string sorted_string = str;
            std::sort(sorted_string.begin(), sorted_string.end());

            if (anagrams.find(sorted_string) == anagrams.end()) {
                anagrams[sorted_string] = {str};
            } else {
                anagrams[sorted_string].push_back(str);
            }
        }

        for (const auto &[key, value] : anagrams) {
            return_vector.push_back(value);
        }

        return return_vector;
    }
};
