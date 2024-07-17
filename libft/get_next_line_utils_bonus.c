/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:13:18 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/04/29 21:27:07 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&s[i]);
	return (NULL);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *warehouse, char *buffer)
{
	char	*joint;
	size_t	len[2];
	size_t	i;

	len[0] = ft_strlen_gnl(warehouse);
	len[1] = ft_strlen_gnl(buffer);
	joint = malloc(sizeof(char) * (len[0] + len[1] + 1));
	if (!joint)
		return (NULL);
	i = 0;
	while (i < len[0])
	{
		joint[i] = warehouse[i];
		i++;
	}
	while (i < len[0] + len[1])
	{
		joint[i] = buffer[i - len[0]];
		i++;
	}
	free(warehouse);
	joint[i] = '\0';
	return (joint);
}
