/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:01:09 by jbrosio           #+#    #+#             */
/*   Updated: 2025/05/07 19:05:55 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*e;

	e = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		e[i] = (unsigned char)c;
		i++;
	}
	s = (void *)e;
	return (s);
}
