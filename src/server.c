#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)ucontext;
	g_data.client_pid = info->si_pid;
	g_data.value = g_data.value << 1;
	if (sig == SIGUSR2)
		++g_data.value;
	if (g_data.status == 7)
	{
		g_data.status = 0;
		ft_putchar_fd(g_data.value, 1);
	}
	else
		++g_data.status;
}

void	set_sigaction(struct sigaction *reaction)
{
	reaction->sa_handler = NULL;
	reaction->sa_sigaction = handler;
	sigemptyset(&reaction->sa_mask);
	sigaddset(&reaction->sa_mask, SIGUSR1);
	sigaddset(&reaction->sa_mask, SIGUSR2);
	reaction->sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, reaction, NULL);
	sigaction(SIGUSR1, reaction, NULL);
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	reaction;

	server_pid = getpid();
	ft_putnbr_fd(server_pid, 1);
	ft_putchar_fd('\n', 1);
	set_sigaction(&reaction);
	g_data.client_pid = 0;
	g_data.status = 0;
	g_data.value = 0;
	while (1)
	{
		1;
	}
	return (0);
}