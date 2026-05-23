class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # We want the largest positive difference between
        # prices[j] and prices[i] where j >= i
        cur_min_before = float('inf')
        max_profit = 0
        for i in range(0, len(prices)):
            if prices[i] < cur_min_before:
                cur_min_before = prices[i]
            profit_if_sell_today = prices[i] - cur_min_before
            if profit_if_sell_today > max_profit:
                max_profit = profit_if_sell_today
        return max_profit
