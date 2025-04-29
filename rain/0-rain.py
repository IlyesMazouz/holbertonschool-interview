#!/usr/bin/python3
"""
Rain Water Trapping
"""


def rain(walls):
    """
    Calculate the amount of water that will be retained after it rains
    """

    if not walls:
        return 0

    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n
    water_trapped = 0

    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    for i in range(1, n - 1):
        water_trapped += max(0, min(left_max[i], right_max[i]) - walls[i])

    return water_trapped
