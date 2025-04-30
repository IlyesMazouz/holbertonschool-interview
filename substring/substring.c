#include "substring.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * find_substring - finds all occurrences of concatenated words in a string.
 * @s: The string to scan.
 * @words: The array of words to find.
 * @nb_words: The number of words in the array.
 * @n: Pointer to an integer to store the number of found indices.
 * Return: An array of indices where substrings were found or NULL if no match.
 */
int *find_substring(char const *s, char const **words, size_t nb_words, int *n)
{
size_t len_s = strlen(s);
size_t word_len = strlen(words[0]);
size_t total_length = word_len * nb_words;
size_t i, j, k;
int *indices = NULL;

*n = 0;

if (len_s < total_length)
return (NULL);

indices = malloc(sizeof(int) * (len_s - total_length + 1));
if (indices == NULL)
return (NULL);

for (i = 0; i <= len_s - total_length; i++)
{
int found = 1;
for (j = 0; j < nb_words; j++)
{
for (k = 0; k < word_len; k++)
{
if (s[i + j * word_len + k] != words[j][k])
{
found = 0;
break;
}
}
if (!found)
break;
}
if (found)
{
indices[*n] = i;
(*n)++;
}
}

return (indices);
}
