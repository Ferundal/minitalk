#include "minitalk.h"




int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_putnbr_fd(server_pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
		(void)server_pid;
	return (0);
}
