class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> return_vector;
        unordered_map<string, vector<string>> seen;

        for (string &str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            seen[sorted].push_back(str);
        }

        for (auto [key, value] : seen) {
            return_vector.push_back(value);
        }

        return return_vector;
    }
};
