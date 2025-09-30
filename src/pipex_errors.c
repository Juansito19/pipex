/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:16:44 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/30 19:49:35 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_puterr(char *str, int error_num, t_command *vars)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error : ", 2);
	if (str)
		ft_putstr_fd(str, 2);
	else if (error_num == 127)
		ft_putstr_fd("command not found\n", 2);
	else if (error_num == 126)
		ft_putstr_fd("command found but no executable\n", 2);
	else
	{
		ft_putstr_fd(strerror(error_num), 2);
		ft_putstr_fd("\n", 2);
	}
	if (vars)
		free_all(vars);
	ft_putstr_fd(RESET, 2);
	exit (2);
}

int	arg_error(int ac, char **av, char **envp)
{
	int	i;

	i = 0;
	if (ac != 5)
		return (1);
	else if (!*envp)
		ft_puterr("Error : enviroment not found\n", 0, NULL);
	else
	{
		while (i < ac)
		{
			if (av[i][0] == '\0')
				return (22);
			i++;
		}
	}
	return (0);
}

void	errors_control(int ac, char **av, char **envp)
{
	if (arg_error(ac, av, envp) == 1)
		ft_puterr("Usage: ./pipex file1 cmd1 cmd2 file2\n", 0, NULL);
	else if (arg_error(ac, av, envp) == 22)
		ft_puterr(NULL, 22, NULL);
}
