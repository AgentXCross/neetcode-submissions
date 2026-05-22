class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums_set = set(nums)
        max_so_far = 1
        consecutive_sequence_len = 1
        for num in nums_set:
            if num - 1 in nums_set:
                continue
            else:
                looking_for = num + 1
                while looking_for in nums_set:
                    consecutive_sequence_len += 1
                    looking_for += 1
                max_so_far = max(max_so_far, consecutive_sequence_len)
        return max_so_far
