#include "minitalk.h"

int	send_int(int d, pid_t server_pid)
{
	int		counter;
	int 	temp_d;

	counter = 8;
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
		usleep(CLIENT_SEND_DEALAY);
	}
	return (0);
}

int	send_char(char c, pid_t server_pid)
{
	int		counter;
	char	temp_c;

	(void)server_pid;
	counter = 8;
	while (counter-- > 0)
	{
		temp_c = c >> counter;
		if (temp_c == 0)
		{
			if (kill(server_pid, SIGUSR1) != 0)
				return (1);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) != 0)
				return (1);
			c = c - (temp_c << counter);
		}
		usleep(CLIENT_SEND_DEALAY);
	}
	return (0);
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

int	check_args(int argc, char **argv)
{
	if (argc < 3 || argc > 4)
	{
		ft_putstr_fd("Wrong arguments amount\n", 2);
		return (1);
	}
	if (ft_isdigit_str(argv[1]) == 0)
	{
		ft_putstr_fd("Wrong client_pid\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (check_args(argc, argv) != 0)
		return (1);
	server_pid = ft_atoi(argv[1]);
	if (send_str(argv[2], server_pid) != 0)
	{
		ft_putstr_fd("Error while sending string\n", 2);
		return (1);
	}
	return (0);
}