/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:30:22 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/06/27 15:40:45 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief allocates memory to nmemb numbers of elements of a determined size
 * and initiates all bytes with zeros.
 * @param nmemb - number of elements
 * @param size - size of these elements. we cant typecast this to fit other 
 * sizes as well.
 * @return void* 
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
