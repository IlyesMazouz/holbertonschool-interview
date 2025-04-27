#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
size_t i, last;

if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
return (0);

if (direction == SLIDE_LEFT)
{
last = 0;
for (i = 1; i < size; i++)
{
if (line[i] == 0)
continue;
if (line[last] == 0)
{
line[last] = line[i];
line[i] = 0;
}
else if (line[last] == line[i])
{
line[last] *= 2;
line[i] = 0;
last++;
}
else
{
last++;
if (last != i)
{
line[last] = line[i];
line[i] = 0;
}
}
}
}
else
{
if (size == 0)
return (0);
last = size - 1;
for (i = size - 1; i > 0; i--)
{
if (line[i - 1] == 0)
continue;
if (line[last] == 0)
{
line[last] = line[i - 1];
line[i - 1] = 0;
}
else if (line[last] == line[i - 1])
{
line[last] *= 2;
line[i - 1] = 0;
if (last > 0)
last--;
}
else
{
if (last > 0)
last--;
if (last != i - 1)
{
line[last] = line[i - 1];
line[i - 1] = 0;
}
}
}
}

return (1);
}
