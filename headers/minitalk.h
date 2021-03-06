/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:33:16 by cjettie           #+#    #+#             */
/*   Updated: 2021/09/10 20:33:29 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# define MINITALK_OUTPUT_DEALAY 30
# define MINITALK_NO_OUTPUT_DEALAY 30
# define VALUE_BIT_SIZE 8
# define MINITALK_OUTPUT_DEALAY_BONUS 30
# define MINITALK_NO_OUTPUT_DEALAY_BONUS 30
# define VALUE_BIT_SIZE_BONUS 8

typedef struct s_current
{
	pid_t	client_pid;
	int		last_byte;
	int		status;
	int		value;
}	t_current;

t_current	g_data;
#endif