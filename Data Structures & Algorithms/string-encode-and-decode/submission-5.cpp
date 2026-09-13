class Solution {
public:
    std::string encode(std::vector<std::string> &strs) {
        std::string encoded_str;

        for (std::string &str : strs) {
            encoded_str += (std::to_string(str.size()) + "#" + str);
        }

        return encoded_str;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> decoded_str;

        int i = 0;
        while (i < s.size()) {
            std::string word_len;
            std::string word;

            while (s[i] != '#') {
                word_len += s[i];
                i++;
            }
            i++;

            int len = std::stoi(word_len);

            decoded_str.push_back(s.substr(i, len));

            i += len;
        }

        return decoded_str;
    }
};
