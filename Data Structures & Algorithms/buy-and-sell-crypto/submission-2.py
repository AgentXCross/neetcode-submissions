class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        cheapest_so_far = float('inf')
        max_profit = 0
        for i in range(0, len(prices)):
            cheapest_so_far = min(cheapest_so_far, prices[i])
            max_profit = max(max_profit, prices[i] - cheapest_so_far)
        return max_profit
