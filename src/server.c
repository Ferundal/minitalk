#include "minitalk.h"

void	set_sigaction(struct sigaction *zero_reaction, \
						struct sigaction *one_reaction)
{
	zero_reaction->sa_handler = NULL;
	zero_reaction->sa_sigaction = zero_handler;
	sigemptyset(&zero_reaction->sa_mask);
	sigaction(SIGUSR1, zero_reaction, NULL);
	one_reaction->sa_handler = NULL;
	one_reaction->sa_sigaction = one_handler;
	sigemptyset(&one_reaction->sa_mask);
	sigaction(SIGUSR2, one_reaction, NULL);
}


int	main(void)
{
	pid_t				server_pid;
	struct sigaction	zero_reaction;
	struct sigaction	one_reaction;
	char 				curr_val;

	server_pid = getpid();
	ft_putnbr_fd(server_pid, 1);
	ft_putchar_fd('\n', 1);
	set_sigaction(&zero_reaction, &one_reaction);
	g_data.status = 0;
	while (1)
	{
		pause();
		curr_val = catch_char_value();
		if (curr_val == '\0')
			curr_val = '\n';
		ft_putchar_fd(curr_val, 1);
	}
	return (0);
}
