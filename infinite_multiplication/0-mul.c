#include "holberton.h"

#define MAX_DIGITS 5000 

/**
 * is_digit - checks if a string contains only digits
 * @str: the string to check
 * Return: 1 if all digits, 0 if not
 */
int is_digit(char *str)
{
while (*str)
{
if (*str < '0' || *str > '9')
return (0);
str++;
}
return (1);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
char *num1 = argv[1];
char *num2 = argv[2];

if (argc != 3)
{
_putchar('E');
_putchar('r');
_putchar('r');
_putchar('o');
_putchar('r');
_putchar('\n');
exit(98);
}

if (!is_digit(num1) || !is_digit(num2))
{
_putchar('E');
_putchar('r');
_putchar('r');
_putchar('o');
_putchar('r');
_putchar('\n');
exit(98);
}

long long n1 = atoll(num1);
long long n2 = atoll(num2);
long long result = n1 * n2;

printf("%lld\n", result);

return (0);
}
