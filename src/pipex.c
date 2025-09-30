/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:46:19 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/30 20:10:21 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/* int xexecve(char *path, char **argv, char **envp)
{
	if (path)
		path = NULL;
	if (argv)
		argv = NULL;
	if (envp)
		envp = NULL;
	return (-1);
}

#define execve xexecve
 */
/* function of the first child process */
void	first_child_process(char **av, char **envp, t_command *vars)
{
	close(vars->fd[0]);
	vars->fd_read = open(av[1], O_RDONLY);
	if (vars->fd_read < 0)
		ft_puterr(NULL, errno, vars);
	if (dup2(vars->fd_read, STDIN_FILENO) < 0)
		ft_puterr(NULL, errno, vars);
	close(vars->fd_read);
	if (dup2(vars->fd[1], STDOUT_FILENO) < 0)
		ft_puterr(NULL, errno, vars);
	close(vars->fd[1]);
	if (execve(vars->bin_in, vars->command_in, envp) < 0)
		ft_puterr(NULL, errno, vars);
}

/* function of the second child process */
void	second_child_process(char **av, char **envp, t_command *vars)
{
	close(vars->fd[1]);
	vars->fd_write = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (vars->fd_write < 0)
		ft_puterr(NULL, errno, vars);
	if (dup2(vars->fd[0], STDIN_FILENO) < 0)
		ft_puterr(NULL, errno, vars);
	close(vars->fd[0]);
	if (dup2(vars->fd_write, STDOUT_FILENO) < 0)
		ft_puterr(NULL, errno, vars);
	close(vars->fd_write);
	if (execve(vars->bin_out, vars->command_out, envp) < 0)
		ft_puterr(NULL, errno, vars);
}

/* function of the parent process */
// void	father_process(char **av, char **envp, t_command *vars)
// {
// 	ft_find(vars, av, envp);
// 	vars->pid = fork();
// 	if (vars->pid < 0)
// 		ft_puterr(NULL, errno, vars);
// 	else if (vars->pid == 0)
// 		first_child_process(av, envp, vars);
// 	else
// 	{
// 		printf("Second child.\n");
// 		close(vars->fd[1]);
// 		vars->fd_write = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0664);
// 		if (vars->fd_write < 0)
// 			ft_puterr(NULL, errno, vars);
// 		if (dup2(vars->fd[0], STDIN_FILENO) < 0)
// 			ft_puterr(NULL, errno, vars);
// 		close(vars->fd[0]);
// 		if (dup2(vars->fd_write, STDOUT_FILENO) < 0)
// 			ft_puterr(NULL, errno, vars);
// 		close(vars->fd_write);
// 		if (execve(vars->bin_out, vars->command_out, envp) < 0)
// 			ft_puterr(NULL, errno, vars);
// 		exit (0);
// 	}
// }
void	father_process(char **av, char **envp, t_command *vars)
{
	ft_find(vars, av, envp);
	vars->pid = fork();
	if (vars->pid < 0)
		ft_puterr(NULL, errno, vars);
	else if (vars->pid == 0)
		first_child_process(av, envp, vars);
	else
	{
		vars->pid2 = fork();
		if (vars->pid2 < 0)
			ft_puterr(NULL, errno, vars);
		else if (vars->pid2 == 0)
			second_child_process(av, envp, vars);
		else
		{
			close(vars->fd[0]);
			close(vars->fd[1]);
			waitpid(vars->pid, NULL, 0);
			waitpid(vars->pid2, NULL, 0);
			if (vars->pid2 == 2)
				exit (2);
			else
				free_all(vars);
		}
	}
}

/* function initialize of the struct */
void	init_struct(t_command *vars)
{
	vars->fd[0] = 0;
	vars->fd[1] = 0;
	vars->fd_write = 0;
	vars->fd_read = 0;
	vars->pid = 0;
	vars->pid2 = 0;
	vars->path = NULL;
	vars->bin_in = NULL;
	vars->bin_out = NULL;
	vars->command_in = NULL;
	vars->command_out = NULL;
	vars->path_dir = NULL;
}

int	main(int ac, char **av, char **envp)
{
	t_command	vars;

	errors_control(ac, av, envp);
	init_struct(&vars);
	if (pipe(vars.fd) == -1)
	{
		ft_putstr_fd(strerror(24), 2);
		exit (24);
	}
	else
		father_process(av, envp, &vars);
	return (0);
}
