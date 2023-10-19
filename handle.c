#include "shell.h"
/**
 * _handle - function to handle Ctr + C signal
 * @signals: signal to handle
 */
void _handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\nsimple_shell $ ", 17);
}

