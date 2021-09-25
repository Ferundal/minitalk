#include "minitalk.h"

int	send_char(int d, pid_t server_pid)
{
	int		counter;
	int 	temp_d;

	counter = VALUE_BIT_SIZE;
	while (counter-- > 0)
	{
		temp_d = d >> counter;
		if (temp_d == 0)
		{
			if (kill(server_pid, SIGUSR1) != 0)
				return (1);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) != 0)
				return (1);
			d = d - (temp_d << counter);
		}
		pause();
	}
	return (0);
}

void	conformation_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)ucontext;
	(void)info;
	usleep(MINITALK_NO_OUTPUT_DEALAY);
}

int	send_str(char *str, pid_t server_pid)
{
	while (*str != '\0')
		if (send_char(*str++, server_pid) != 0)
			return (1);
	if (send_char('\n', server_pid) != 0)
		return (1);
	return (0);
}

int	check_args(int argc, char **argv, pid_t	*server_pid)
{
	if (argc != 3)
	{
		ft_putstr_fd("Wrong arguments amount\n", 2);
		return (1);
	}
	if (ft_isdigit_str(argv[1]) == 0)
	{
		ft_putstr_fd("Wrong client_pid\n", 2);
		return (1);
	}
	*server_pid = ft_atoi(argv[1]);
	if (*server_pid == 0)
	{
		ft_putstr_fd("Wrong pid\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	conformation;

	if (check_args(argc, argv, &server_pid) != 0)
		return (1);
	conformation.sa_sigaction = conformation_handler;
	sigemptyset(&conformation.sa_mask);
	sigaddset(&conformation.sa_mask, SIGUSR1);
	conformation.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &conformation, NULL);
	g_data.status = 0;
	g_data.value = (ft_strlen(argv[2]) + 1) * 8;
	if (send_str(argv[2], server_pid) != 0)
	{
		ft_putstr_fd("Error while sending string\n", 2);
		return (1);
	}
	return (0);
}
