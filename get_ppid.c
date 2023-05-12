#include "main.h"

/**
 * _process_ppid - gets process id of current process
 * @param: none
 * Return: pid
*/

pid_t _process_ppid(void)
{
	return (getppid());
}
