#include "shell.h"
/**
 * _putchar - prints "_putchar" followed by a newline character
 */
void _putchar(void)
{
	char str[] = "_putchar\n";
	write(1, str, sizeof(str) - 1);
}

