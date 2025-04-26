#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""

import sys

status_codes = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0,
}

total_size = 0
line_count = 0

def print_stats():
    """
    Prints the accumulated statistics
    """
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))

try:
    for line in sys.stdin:
        parts = line.split()
        if len(parts) >= 7:
            file_size = parts[-1]
            status_code = parts[-2]

            try:
                total_size += int(file_size)
            except Exception:
                pass

            if status_code in status_codes:
                status_codes[status_code] += 1

        line_count += 1

        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    """
    Handles a keyboard interruption (CTRL + C)
    """
    print_stats()
    raise

print_stats()
