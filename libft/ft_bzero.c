/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:24:13 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/06/27 14:39:01 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief sets the first n bytes to 0.
 * This function is used to initiate structures.
 * we can typecast size_t to other data types to initiate structures for ex. 
 * @param s 
 * @param n 
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
