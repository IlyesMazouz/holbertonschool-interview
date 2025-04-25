#!/usr/bin/python3


def minOperations(n):
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
