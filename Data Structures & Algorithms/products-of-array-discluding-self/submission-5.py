class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left_arr = []
        right_arr = []
        return_lst = []
        nums_len = len(nums)
        if nums_len == 1:
            return nums
        for i in range(1, nums_len):
            right_arr.append(nums[i])

        for num in nums:
            product_except_num = 1
            for l in left_arr:
                product_except_num *= l
            for r in right_arr:
                product_except_num *= r
            return_lst.append(product_except_num)
            left_arr.append(num)
            right_arr.pop(0)
        return return_lst
            
