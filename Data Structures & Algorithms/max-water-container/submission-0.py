class Solution:
    def get_area(self, idx1, h1, idx2, h2):
        height = min(h1, h2)
        width = abs(idx2 - idx1)
        return height * width

    def maxArea(self, heights: List[int]) -> int:
        heights_len = len(heights)
        l = 0
        r = heights_len - 1
        cur_max = float('-inf')
        while l < r:
            cur_area = self.get_area(l, heights[l], r, heights[r])
            if cur_area > cur_max:
                cur_max = cur_area
            if heights[l] < heights[r]:
                l += 1
            else:
                r -= 1
        return cur_max