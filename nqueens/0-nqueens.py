#!/usr/bin/python3
"""Solves the N-Queens problem"""

import sys


def is_safe(board, row, col, n):
    """Check if it's safe to place a queen at board[row][col]"""
    for i in range(row):
        if board[i] == col or board[i] - i == col - row or board[i] + i == col + row:
            return False
    return True


def solve_nqueens(n, row, board, solutions):
    """Solve the N-Queens problem using backtracking"""
    if row == n:
        solution = []
        for i in range(n):
            solution.append([i, board[i]])
        solutions.append(solution)
        return
    for col in range(n):
        if is_safe(board, row, col, n):
            board[row] = col
            solve_nqueens(n, row + 1, board, solutions)


def main():
    """Main entry point"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []
    board = [-1] * n
    solve_nqueens(n, 0, board, solutions)

    for sol in solutions:
        print(sol)


if __name__ == "__main__":
    main()
