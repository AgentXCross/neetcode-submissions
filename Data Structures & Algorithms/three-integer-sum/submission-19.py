class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        nums_len = len(nums)
        triplets = []
        for i in range(0, nums_len):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            # target is the sum of the other 2 we want
            target = -nums[i]
            l = i + 1
            r = nums_len - 1
            while l < r:
                sum_l_r = nums[l] + nums[r]
                if sum_l_r == target:
                    triplets.append([nums[i], nums[l], nums[r]])
                    l += 1
                    r -= 1
                    while l < r and nums[l] == nums[l - 1]:
                        l += 1
                    while l < r and nums[r] == nums[r + 1]:
                        r -= 1
                elif sum_l_r < target:
                    l += 1
                else:
                    r -= 1
        return triplets
                
