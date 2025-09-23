/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:37:14 by jbrosio           #+#    #+#             */
/*   Updated: 2025/05/07 19:05:30 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*c;
	const unsigned char	*o;

	c = (unsigned char *)dest;
	o = (const unsigned char *)src;
	i = n;
	if ((!dest && !src))
		return (NULL);
	if (o < c)
	{
		while (i > 0)
		{
			i--;
			c[i] = o[i];
		}
	}
	else
		ft_memcpy(c, o, n);
	return ((void *)dest);
}
