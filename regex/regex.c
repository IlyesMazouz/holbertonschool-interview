#include "regex.h"

/**
 * regex_match - checks if a given pattern matches a string
 * @str: the string to scan
 * @pattern: the regular expression pattern
 * 
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
if (*pattern == '\0')
return (*str == '\0');

if (*(pattern + 1) == '*') {
if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
} else {
return (regex_match(str, pattern + 2));
}
}

if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
return (regex_match(str + 1, pattern + 1));
}

return (0);
}
