#include "minitalk.h"

void	zero_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)ucontext;
	(void)info;
	g_data.value = g_data.value << 1;
	if (g_data.status == VALUE_BIT_SIZE)
	{
		ft_putchar_fd(g_data.value, 1);
		usleep(MINITALK_SERVER_DEALAY);
		g_data.status = 1;
		g_data.value = 0;
	}
	else
		++g_data.status;
	g_data.client_pid = info->si_pid;
}

void	one_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)ucontext;
	(void)info;
	g_data.value = g_data.value << 1;
	++g_data.value;
	if (g_data.status == VALUE_BIT_SIZE)
	{
		ft_putchar_fd(g_data.value, 1);
		usleep(MINITALK_SERVER_DEALAY);
		g_data.status = 1;
		g_data.value = 0;
	}
	else
		++g_data.status;
	g_data.client_pid = info->si_pid;
}

void	set_sigaction(struct sigaction *zero_reaction, \
						struct sigaction *one_reaction)
{
	zero_reaction->sa_sigaction = zero_handler;
	sigemptyset(&zero_reaction->sa_mask);
	sigaddset(&zero_reaction->sa_mask, SIGUSR1);
	sigaddset(&zero_reaction->sa_mask, SIGUSR2);
	zero_reaction->sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, zero_reaction, NULL);
	one_reaction->sa_sigaction = one_handler;
	sigemptyset(&one_reaction->sa_mask);
	sigaddset(&one_reaction->sa_mask, SIGUSR1);
	sigaddset(&one_reaction->sa_mask, SIGUSR2);
	one_reaction->sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, one_reaction, NULL);
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	zero_reaction;
	struct sigaction	one_reaction;

	server_pid = getpid();
	ft_putnbr_fd(server_pid, 1);
	ft_putchar_fd('\n', 1);
	set_sigaction(&zero_reaction, &one_reaction);
	g_data.status = 1;
	g_data.value = 0;
	while (1)
	{
		pause();
		kill(g_data.client_pid, SIGUSR1);
	}
	return (0);
}
