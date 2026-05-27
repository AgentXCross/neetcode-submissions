class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        curr_unique = set()
        longest_so_far = float('-inf')
        l = 0
        s_len = len(s)
        if s_len == 0:
            return 0
        for r in range(0, s_len):
            if s[r] in curr_unique:
                longest_so_far = max(longest_so_far, r - l)
                while s[l] != s[r]:
                    curr_unique.remove(s[l])
                    l += 1
                l += 1
            else:
                curr_unique.add(s[r])
                longest_so_far = max(longest_so_far, r - l + 1)
        return longest_so_far
