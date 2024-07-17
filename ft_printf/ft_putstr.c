/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:31:10 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/02 13:12:24 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(const char *s, int *count)
{
	int	len; 

	if (!s)
	{
		write(1, "(null)", 6);
		*count += 6;
	}
	else
	{
		len = ft_strlen(s);
		write(1, s, len);
		*count += len;
	}
}
