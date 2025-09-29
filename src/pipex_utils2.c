/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:26:41 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/29 23:33:58 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_all(t_command *vars)
{
	if (vars->path)
		free(vars->path);
	if (vars->bin_out)
		free(vars->bin_out);
	if (vars->bin_in)
		free(vars->bin_in);
	if (vars->path_dir)
		free_array(vars->path_dir);
	if (vars->command_in)
		free_array(vars->command_in);
	if (vars->command_out)
		free_array(vars->command_out);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_count_quote(char *command)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (command[i])
	{
		if (command[i] == '\'')
			count++;
		i++;
	}
	return (count);
}

/* function that counts the quotes */
char	**ft_check_command(char *command)
{
	char	**res;

	res = NULL;
	if (ft_count_quote(command) % 2 == 0)
	{
		res = ft_split(command, '\'');
		if (!res)
			return (NULL);
	}
	else
	{
		res = ft_split(command, ' ');
		if (!res)
			return (NULL);
	}
	return (res);
}
