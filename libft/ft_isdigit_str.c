/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:04:47 by cjettie           #+#    #+#             */
/*   Updated: 2021/10/23 14:04:49 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit_str(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str != '\0')
		if (ft_isdigit(*str++) == 0)
			return (0);
	return (1);
}
