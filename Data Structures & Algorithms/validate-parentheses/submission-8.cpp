class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> brackets;

        std::unordered_set<char> open{'(', '[', '{'};
        std::unordered_set<char> close{')', ']', '}'};

        for (char &c : s) {
            if (open.find(c) != open.end()) {
                brackets.push(c);
            } else if (close.find(c) != close.end()) {
                if (c == ')') {
                    if (!brackets.empty() && brackets.top() == '(') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                } else if (c == ']') {
                    if (!brackets.empty() && brackets.top() == '[') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                } else {
                    if (!brackets.empty() && brackets.top() == '{') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                }
            } else {
                continue;
            }
        }

        if (brackets.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
