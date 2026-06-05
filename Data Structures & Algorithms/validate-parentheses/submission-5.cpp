class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;

        unordered_set<char> opens = {'(', '{', '['};
        unordered_set<char> closes = {')', '}', ']'};

        for (char &c : s) {
            if (opens.find(c) != opens.end()) {
                brackets.push(c);
            } else if (closes.find(c) != closes.end()) {
                if (brackets.empty()) {
                    return false;
                } else if (c == ')') {
                    if (brackets.top() == '(') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                } else if (c == ']') {
                    if (brackets.top() == '[') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                } else if (c == '}') {
                    if (brackets.top() == '{') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                }
            }
        }

        if (brackets.empty()) {
            return true;
        }

        return false;
    }
};
