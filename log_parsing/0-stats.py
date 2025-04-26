#!/usr/bin/python3
"""
Script that reads stdin line by line, computes metrics, and prints the statistics:
- Total file size.
- Number of occurrences for HTTP status codes: 200, 301, 400, 401, 403, 404, 405, 500.
The statistics are printed every 10 lines or after a keyboard interrupt.
"""

import sys

# Dictionary to count occurrences of specific HTTP status codes
status_codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0,
}

total_size = 0  # Total accumulated file size
line_count = 0  # Line counter


def print_stats():
    """
    Prints the accumulated statistics:
    - Total file size.
    - Number of occurrences for each HTTP status code that has been encountered.

    Status codes that have not appeared are not printed.
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
    print_stats()
    raise

print_stats()
