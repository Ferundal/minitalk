#include "minitalk.h"

void	zero_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)ucontext;
	g_data.value = 0;
	g_data.client_pid = info->si_pid;
	g_data.status = 1;
}

void	one_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)ucontext;
	g_data.value = 1;
	g_data.client_pid = info->si_pid;
	g_data.status = 1;
}

char	catch_char_value(void)
{
	int		value;
	int		counter;

	value = 0;
	counter = 0;
	while (counter < 8)
	{
		while (g_data.status == 0)
			(void)g_data;
		value = value << 1;
		value += g_data.value;
		++counter;
		g_data.status = 0;
	}
	return ((char)value);
}