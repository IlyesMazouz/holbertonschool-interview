#!/usr/bin/python3
"""
Module for canUnlockAll method
"""

from collections import deque

def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened
    """
    n = len(boxes)
    visited = set()
    queue = deque([0])  

    while queue:
        current_box = queue.popleft()
        visited.add(current_box)

        for key in boxes[current_box]:
            if key not in visited and key < n:
                queue.append(key)

    return len(visited) == n

if __name__ == "__main__":
    boxes1 = [[1], [2], [3], [4], []]
    print(canUnlockAll(boxes1))  

    boxes2 = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
    print(canUnlockAll(boxes2))  

    boxes3 = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
    print(canUnlockAll(boxes3))  
