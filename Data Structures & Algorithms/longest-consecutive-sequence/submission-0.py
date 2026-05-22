class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums_set = set(nums)
        max_so_far = 1
        consecutive_sequence_len = 1
        for i in range(1, len(nums_set)):
            if nums_set[i] == nums_set[i - 1] + 1:
                consecutive_sequence_len += 1
            else:
                max_so_far = max(max_so_far, consecutive_sequence_len)
                consecutive_sequence_len = 1
        return max_so_far
