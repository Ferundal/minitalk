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
# define CLIENT_SEND_DEALAY 100000

typedef struct s_current
{
	pid_t	client_pid;
	int		status;
	int 	value;
} t_current;

t_current	g_data;

int		send_int(int d, pid_t server_pid);
int		send_char(char c, pid_t server_pid);
int		send_str(char *str, pid_t server_pid);
void	zero_handler(int sig, siginfo_t *info, void *ucontext);
void	one_handler(int sig, siginfo_t *info, void *ucontext);
char	catch_char_value(void);
#endif