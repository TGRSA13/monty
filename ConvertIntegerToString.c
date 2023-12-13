#include <stdlib.h>

char *convertIntToString(int num);
unsigned int absoluteValue(int);
int getNumBaseLength(unsigned int num, unsigned int base);
void fillNumBaseBuffer(unsigned int num, unsigned int base, char *buffer, int bufferSize);

/**
 * convertIntToString - Converts an integer to a string.
 * @num: Number to convert.
 *
 * Return: A dynamically allocated string representation of the integer.
 *         NULL if malloc fails.
 */
char *convertIntToString(int num)
{
unsigned int temp;
int length = 0;
long num_l = 0;
char *result;

temp = absoluteValue(num);
length = getNumBaseLength(temp, 10);

if (num < 0 || num_l < 0)
length++; /* negative sign */

result = malloc(length + 1); /* create a new string */
if (!result)
return (NULL);

fillNumBaseBuffer(temp, 10, result, length);
if (num < 0 || num_l < 0)
result[0] = '-';

return ((result)i);
}

/**
 * absoluteValue - Gets the absolute value of an integer.
 * @i: Integer to get the absolute value of.
 *
 * Return: Unsigned integer absolute representation of i.
 */
unsigned int absoluteValue(int i)
{
if (i < 0)
return (-(unsigned int)i);
return ((unsigned int)i);
}

/**
 * getNumBaseLength - Gets the length of the buffer needed for an unsigned int.
 * @num: Number to get the length needed for.
 * @base: Base of the number representation used by the buffer.
 *
 * Return: Integer containing the length of the buffer needed (doesn't contain null byte).
 */
int getNumBaseLength(unsigned int num, unsigned int base)
{
int length = 1; /* all numbers contain at least one digit */

while (num > base - 1)
{
length++;
num /= base;
}
return ((length)i);
}

/**
 * fillNumBaseBuffer - Fills a buffer with correct numbers up to base 36.
 * @num: Number to convert to a string given base.
 * @base: Base of the number used in conversion, only works up to base 36.
 * @buffer: Buffer to fill with the result of the conversion.
 * @bufferSize: Size of the buffer in bytes.
 *
 * Return: Always void.
 */
void fillNumBaseBuffer(unsigned int num, unsigned int base, char *buffer, int bufferSize)
{
int remainder, i = bufferSize - 1;

buffer[bufferSize] = '\0';
while (i >= 0)
{
remainder = num % base;
if (remainder > 9) /* return lowercase ASCII val representation */
buffer[i] = remainder + 87; /* 10 will be a, 11 = b, ... */
else
buffer[i] = remainder + '0';
num /= base;
i--;
}
}
