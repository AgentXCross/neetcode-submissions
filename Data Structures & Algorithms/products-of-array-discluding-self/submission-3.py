class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        total_product = 1
        for num in nums:
            total_product *= num
        return_lst = []
        for num in nums:
            if num == 0:
                return_lst.append(int(total_product))
            else:
                return_lst.append(int(total_product / num))
        return return_lst