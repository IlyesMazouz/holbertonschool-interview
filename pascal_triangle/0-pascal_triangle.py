#!/usr/bin/python3
"""
A function that generates Pascal's Triangle
"""


def pascal_triangle(n):
    """
    Generates Pascal's Triangle up to the nth row
    """
    if n <= 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        row = [1]
        for j in range(1, i):
            row.append(triangle[i - 1][j - 1] + triangle[i - 1][j])
        row.append(1)
        triangle.append(row)

    return triangle
