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

# define CLIENT_SEND_DEALAY 100


int	send_int(int d, pid_t server_pid);
int	send_char(char c, pid_t server_pid);
int	send_str(char *str, pid_t server_pid);
void	zero_handler(int sig, siginfo_t *info, void *ucontext);

#endif