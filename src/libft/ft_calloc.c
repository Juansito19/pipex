/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:56:41 by jbrosio           #+#    #+#             */
/*   Updated: 2025/05/07 19:03:54 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*spaces;

	spaces = (void *)malloc(nmemb * size);
	if (!spaces)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (spaces);
	ft_bzero(spaces, nmemb * size);
	return (spaces);
}
