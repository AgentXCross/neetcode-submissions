class Solution:
    def isValid(self, s: str) -> bool:
        brackets = []
        brackets_len = 0
        for char in s:
            if char == '(' or char == '{' or char == '[':
                brackets.append(char)
                brackets_len += 1
            elif char == ')':
                if brackets_len == 0:
                    return False
                elif brackets[brackets_len - 1] == '(':
                    brackets.pop(brackets_len - 1)
                    brackets_len -= 1
                else:
                    return False
            elif char == '}':
                if brackets_len == 0:
                    return False
                elif brackets[brackets_len - 1] == '{':
                    brackets.pop(brackets_len - 1)
                    brackets_len -= 1
                else:
                    return False
            elif char == ']':
                if brackets_len == 0:
                    return False
                elif brackets[brackets_len - 1] == '[':
                    brackets.pop(brackets_len - 1)
                    brackets_len -= 1
                else:
                    return False
        if brackets_len == 0:
            return True
        return False 