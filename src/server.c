#include "minitalk.h"

void	set_sigaction(struct sigaction *zero_reaction, \
						struct sigaction *one_reaction)
{
	zero_reaction->sa_handler = NULL;
	zero_reaction->sa_sigaction = zero_handler;
	zero_reaction->sa_mask = 0;

	sigaction(SIGUSR1, zero_reaction, NULL);
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
	while (1)
		(void)server_pid;
	return (0);
}
