class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        total_product = 1
        for num in nums:
            total_product *= num
        return_lst = []
        for num in nums:
            return_lst.append(total_product / num)
        return return_lst