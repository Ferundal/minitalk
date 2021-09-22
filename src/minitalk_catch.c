#include "minitalk.h"

void	zero_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)ucontext;
	g_data.client_pid = info->si_pid;
	g_data.value = g_data.value << 1;
	if (g_data.status == 7)
	{
		g_data.status = 0;
		ft_putchar_fd(g_data.value, 1);
	}
	else
		++g_data.status;
}

void	one_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)ucontext;
	g_data.client_pid = info->si_pid;

	g_data.value = g_data.value << 1;
	++g_data.value;
	if (g_data.status == 7)
	{
		g_data.status = 0;
		ft_putchar_fd(g_data.value, 1);
	}
	else
		++g_data.status;
}