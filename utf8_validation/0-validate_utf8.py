#!/usr/bin/python3
"""
UTF-8 Validation Module
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding
    """
    number_of_bytes = 0

    for byte in data:
        byte = byte & 0xFF

        if number_of_bytes == 0:
            if (byte >> 5) == 0b110:
                number_of_bytes = 1
            elif (byte >> 4) == 0b1110:
                number_of_bytes = 2
            elif (byte >> 3) == 0b11110:
                number_of_bytes = 3
            elif byte >> 7:
                return False
        else:
            if (byte >> 6) != 0b10:
                return False
            number_of_bytes -= 1

    return number_of_bytes == 0
