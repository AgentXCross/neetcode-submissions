class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        largest_so_far = float('-inf')
        cur_substr = set()
        l = 0
        s_len = len(s)
        if s_len == 0: 
            return 0
        for r in range(0, s_len):
            if s[r] in cur_substr:
                largest_so_far = max(largest_so_far, r - l)
                while s[l] != s[r]:
                    cur_substr.remove(s[l])
                    l += 1
                l += 1
            else:
                cur_substr.add(s[r])
                largest_so_far = max(largest_so_far, r - l + 1)
        return largest_so_far


