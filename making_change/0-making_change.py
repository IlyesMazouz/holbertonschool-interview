#!/usr/bin/python3
"""
Module for the makeChange function
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given amount
    """
    if total <= 0:
        return 0

    max_val = float("inf")
    dp = [0] + [max_val] * total

    for coin in coins:
        for i in range(coin, total + 1):
            if dp[i - coin] != max_val:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != max_val else -1
