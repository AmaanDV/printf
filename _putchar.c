#include <unistd.h>
#include "main.h"
/**
 * _putchar - This  writes the character c to stdout output file 
 * @c: The character to print the standardard output
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */


int _putchar(char c)
{
	return (write(1, &c, 1));
}
