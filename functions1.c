#include "main.h"

/************************* PRINTS THE  UNSIGNED NUMBER FORMAT *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: Lists   of arguments
 * @buffer: Buffer array to handle prin function t
 * @flags:  Calculates the  active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specification
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINTS THE UNSIGNED NUMBERS IN OCTAL FORMAT ****************/
/**
 * print_octal - Prints an unsigned number in octal notation format
 * @types: Lists  of arguments
 * @buffer: Buffer array to handle print function
 * @flags:  Calculates the  active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specification
 * Return: Number of chars printed onto the screen
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINTS THE  UNSIGNED NUMBER IN UPPER HEXADECIMAL SIGN **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation sign
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print function 
 * @flags:  Calculates the active flags
 * @width: get width of function 
 * @precision: Precision specification
 * @size: Size specification
 * Return: Number of chars printed out 
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXADECIMAL  NUMBER  IN LOWER OR UPPER CASES  **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper Cases
 * @types: Lists  of arguments
 * @map_to: Arrays of values to be  mapped  the number to characters
 * @buffer: Buffer array to handle print function
 * @flags:  Calculates the active flags
 * @flag_ch: Calculates the active flags
 * @width: get width of function
 * @precision: Precision specifications
 * @size: Size specification
 * @size: Size specification
 * Return: Number of chars printed to screen
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

