class Solution {
private:
    bool is_alphanumeric(char c) {
        if (c >= '0' && c <= '9' || 
            c >= 'a' && c <= 'z' ||
            c >= 'A' && c <= 'Z'
        ) {
            return true;
        }

        return false;
    }

    char lower(char c) {
        if (c >= '0' && c <= '9') {
            return c;
        } else if (c >= 'a' && c <= 'z') {
            return c;
        } else {
            return c - 'A' + 'a';
        }
    }
    
public:
    bool isPalindrome(std::string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (is_alphanumeric(s[l]) && is_alphanumeric(s[r])) {
                char left = lower(s[l]);
                char right = lower(s[r]);

                if (left != right) {
                    return false;
                }

                l++;
                r--;

                continue;
            }

            while (!is_alphanumeric(s[l])) {
                l++;
            }

            while(!is_alphanumeric(s[r])) {
                r--;
            }
        }

        return true;
    }
};
