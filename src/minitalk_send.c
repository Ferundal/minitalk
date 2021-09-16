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
	if (send_char(*str, server_pid) != 0)
		return (1);
	return (0);
}