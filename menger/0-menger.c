#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * is_blank - checks if a position should be a space
 * @row: row index
 * @col: column index
 *
 * Return: 1 if should be a space, 0 otherwise
 */
int is_blank(int row, int col)
{
while (row > 0 || col > 0)
{
if (row % 3 == 1 && col % 3 == 1)
return (1);
row /= 3;
col /= 3;
}
return (0);
}

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the sponge
 */
void menger(int level)
{
int size, row, col;

if (level < 0)
return;

size = pow(3, level);

for (row = 0; row < size; row++)
{
for (col = 0; col < size; col++)
{
if (is_blank(row, col))
printf(" ");
else
printf("#");
}
printf("\n");
}
}
