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
# define CLIENT_SEND_DEALAY 10

typedef struct s_current
{
	pid_t	client_pid;
	int		status;
	int 	value;
} t_current;

t_current	g_data;
#endif