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
# define MINITALK_CLIENT_DEALAY 15
# define VALUE_BIT_SIZE 8
# define MINITALK_SERVER_DEALAY_BONUS 5
# define MINITALK_CLIENT_DEALAY_BONUS 5
# define VALUE_BIT_SIZE_BONUS 8

typedef struct s_current
{
	pid_t	client_pid;
	int		status;
	int 	value;
} t_current;

t_current	g_data;
#endif