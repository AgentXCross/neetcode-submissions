class Solution {
private:
    bool alphanumeric(char &c) {
        if (c >= '0' && c <= '9') {
            return true;
        }
        if (c >= 'a' && c <= 'z') {
            return true;
        }
        if (c >= 'A' && c <= 'Z') {
            return true;
        }
        return false;
    }
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            while (l < r && !alphanumeric(s[l])) {
                l++;
            }
            while (l < r && !alphanumeric(s[r])) {
                r--;
            }

            if (s[l] <= 'Z' && s[l] >= 'A') {
                s[l] = s[l] - 'A' + 'a';
            }
            if (s[r] <= 'Z' && s[r] >= 'A') {
                s[r] = s[r] - 'A' + 'a';
            }

            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
