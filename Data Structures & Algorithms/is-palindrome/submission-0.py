class Solution:
    def isPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s)
        while l < r:
            while not (s[l].isalpha() or s[l].isdigit()):
                l += 1
            while not(s[r].isalpha() or s[r].isdigit()):
                r -= 1
            if l >= r:
                continue
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True