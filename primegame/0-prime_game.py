#!/usr/bin/python3
"""
Module for the isWinner function
"""


def sieve_of_eratosthenes(limit):
    """
    Returns a list of booleans where True represents that the index is a prime number
    """
    primes = [True] * (limit + 1)
    primes[0] = primes[1] = False
    for i in range(2, int(limit**0.5) + 1):
        if primes[i]:
            for j in range(i * i, limit + 1, i):
                primes[j] = False
    return primes


def isWinner(x, nums):
    """
    Determines the winner of the most rounds in a prime game
    """
    limit = 10000
    primes = sieve_of_eratosthenes(limit)

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        current_primes = [p for p in range(2, n + 1) if primes[p]]

        turn = 0
        while current_primes:
            prime = current_primes.pop(0)
            current_primes = [p for p in current_primes if p % prime != 0]

            turn = 1 - turn

        if turn == 0:
            ben_wins += 1
        else:
            maria_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
