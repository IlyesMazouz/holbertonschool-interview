#!/usr/bin/python3
"""
Determines if all boxes can be opened
"""


def canUnlockAll(boxes):
    """
    Checks whether all boxes can be unlocked starting from box 0
    """
    if not isinstance(boxes, list):
        return False
    if not all(isinstance(box, list) for box in boxes):
        return False

    n = len(boxes)
    opened = set([0])
    keys = set(boxes[0])

    while keys:
        key = keys.pop()
        if key < n and key not in opened:
            opened.add(key)
            keys.update(boxes[key])

    return len(opened) == n
