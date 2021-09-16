#include "minitalk.h"

int	check_args(int argc, char **argv)
{
	if (argc < 3 || argc > 4)
	{
		ft_putstr_fd("Wrong arguments amount\n", 2);
		return (1);
	}
	if (ft_isdigit_str(argv[1]) == 0)
	{
		ft_putstr_fd("Wrong pid\n", 2);
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