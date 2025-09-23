/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_sign_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:57:30 by jbrosio           #+#    #+#             */
/*   Updated: 2025/08/16 20:51:30 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_double_sign_error(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	if (str[i] == '-' && !str[1])
		return (0);
	while (str[i])
	{
		if (i > 0 && str[i] == '-')
			return (0);
		if (str[i] == '-' && !flag)
			flag = 1;
		else if (ft_isdigit(str[i]) && flag)
			flag = 0;
		else if (str[i] == '-' && flag)
			return (0);
		else if (str[i] == '0' && flag)
			return (0);
		i++;
	}
	return (1);
}
