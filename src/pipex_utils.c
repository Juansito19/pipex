/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:15:50 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/20 18:43:35 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"


/* function that finds the specific folder of the command */
/* 					 second command						  */
void	find_bin_out(t_command *vars, char **av)
{
	char	*aux;
	int		i;

	i = 0;
	vars->command_out = ft_check_command(av[3]);
	if (!vars->command_out)
		ft_puterr(NULL, 12, vars);
	while (vars->path_dir[i])
	{
		if (vars->bin_out)
			free(vars->bin_out);
		aux = ft_strjoin(vars->path_dir[i], "/");
		vars->bin_out = ft_strjoin(aux, vars->command_out[0]);
		if (!vars->bin_out)
			ft_puterr(NULL, 12, vars);
		if (access(vars->bin_out, X_OK) == 0)
			break ;
		free(aux);
		i++;
	}
	if (vars->path_dir[i] == NULL)
		ft_puterr(NULL, 2, vars);
	free(aux);
}

/* function that finds the specific folder of the command */
/* 					  first command						  */
void	find_bin_in(t_command *vars, char **av)
{
	char	*aux;
	int		i;

	i = 0;
	vars->command_in = ft_check_command(av[2]);
	if (!vars->command_in)
		ft_puterr(NULL, 12, vars);
	while (vars->path_dir[i])
	{
		if (vars->bin_in)
			free(vars->bin_in);
		aux = ft_strjoin(vars->path_dir[i], "/");
		vars->bin_in = ft_strjoin(aux, vars->command_in[0]);
		if (!vars->bin_in)
			ft_puterr(NULL, 12, vars);
		if (access(vars->bin_in, X_OK) == 0)
			break ;
		free(aux);
		i++;
	}
	if (vars->path_dir[i] == NULL)
		ft_puterr(NULL, 2, vars);
	free(aux);
}

/* function that finds the PATH */
void	find_path(t_command *vars, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			vars->path = ft_strdup(envp[i]);
			if (!vars->path)
				ft_puterr(NULL, 12, vars);
			break ;
		}
		i++;
	}
	if (!vars->path)
		ft_puterr("Error: PATH variable not found in environment\n", 0, vars);
	vars->path_dir = ft_split(vars->path, ':');
	if (!vars->path_dir)
		ft_puterr(NULL, 12, vars);
}

void	ft_find(t_command *vars, char **av, char **envp)
{
	find_path(vars, envp);
	find_bin_in(vars, av);
	find_bin_out(vars, av);
}
