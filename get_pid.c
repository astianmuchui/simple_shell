#include "main.h"

/**
 * _process_id - gets process id of current process
 * @param: none
 * Return: pid
*/

pid_t _process_id(void)
{
    return (getpid());
}
