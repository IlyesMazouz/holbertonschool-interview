#!/usr/bin/python3
"""
Calculates the minimum number of operations required to
reach exactly n 'H' characters
in a file starting from a single 'H' using "Copy All" and "Paste" operations.
"""


def minOperations(n):
    """
    Determines the fewest number of operations needed
    to reach exactly n 'H' characters in a file.
    """
    if n <= 1:
        return 0

    operations = 0

    i = 2

    while i <= n:
        if n % i == 0:
            operations += i
            n //= i
        else:
            i += 1

    return operations
