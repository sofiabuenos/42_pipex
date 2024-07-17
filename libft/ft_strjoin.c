/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:02:02 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/04 17:03:13 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (ft_strdup(""));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < lens1)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (i < lens1 + lens2)
	{
		ptr[i] = s2[i - lens1];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int	main(void)
// {
// 	char *s1 = "my favorite animal is";
// 	char *s2 = " ";
// 	char *s3 = "the nyancat";
// 	char *res = ft_strjoin(ft_strjoin(s1, s2), s3);
// 	printf("%s", res);
// }