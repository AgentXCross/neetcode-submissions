class Solution:
    def reverse_array(self, arr: List[int], arr_len: int) -> List[int]:
        l = 0
        r = arr_len - 1
        while l < r:
            arr[l], arr[r] = arr[r], arr[l]
            l += 1
            r -= 1
        
    def trap(self, height: List[int]) -> int:
        left_max = []
        right_max = []
        height_len = len(height)
        cur_left_max = 0
        cur_right_max = 0
        total_area = 0
        for i in range(0, height_len):
            left_max.append(cur_left_max)
            if height[i] > cur_left_max:
                cur_left_max = height[i]
        for j in range(height_len - 1, -1, -1):
            right_max.append(cur_right_max)
            if height[j] > cur_right_max:
                cur_right_max = height[j]
        self.reverse_array(right_max, height_len)
        for k in range(0, height_len):
            total_area += max(0, min(left_max[k], right_max[k]) - height[k])
        return total_area
            
