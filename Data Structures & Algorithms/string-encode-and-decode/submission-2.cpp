class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (string &str : strs) {
            int length = str.length();
            encoded += to_string(length);
            encoded += "#";
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        for (int i = 0; i < s.length(); ) {
            string length;
            while (s[i] != '#') {
                length += s[i];
                i++;
            }
            i++;
            string str;
            for (int j = 0; j < stoi(length); j++) {
                str += s[i];
                i++;
            }
            decoded.push_back(str);
        }
        return decoded;
    }
};
