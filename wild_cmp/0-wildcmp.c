#include "holberton.h"

/**
 * wildcmp - Compares two strings considering the special character *
 * @s1: The first string to compare
 * @s2: The second string to compare, which may contain the special character *
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
if (*s1 == '\0' && *s2 == '\0')
return (1);
if (*s2 == '*')
{
if (*(s2 + 1) == '\0')
return (1);
if (*s1 == '\0')
return (wildcmp(s1, s2 + 1));
return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
}
if (*s1 == *s2)
return (wildcmp(s1 + 1, s2 + 1));
return (0);
}
