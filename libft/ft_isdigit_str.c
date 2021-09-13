#include "libft.h"

int		ft_isdigit_str(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str != '\0')
		if (ft_isdigit(*str++) == 0)
			return (0);
	return (1);
}