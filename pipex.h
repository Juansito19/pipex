/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:46:39 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/21 21:50:32 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h" 
# include <sys/wait.h>
# include <errno.h>

# ifndef RED
#  define RED "\033[31m"
# endif
# ifndef RESET
#  define RESET "\033[0m"
# endif

typedef struct s_command
{
	int		fd[2];
	int		fd_read;
	int		fd_write;
	pid_t	pid;
	pid_t	pid2;
	char	*path;
	char	*bin_in;
	char	*bin_out;
	char	**command_in;
	char	**command_out;
	char	**path_dir;
}	t_command;

/* errors */
void	ft_puterr(char *str, int error_num, t_command *vars);
void	errors_control(int ac, char **av, char **envp);

/* utils */
void	free_all(t_command *vars);
void	free_array(char **str);
int		ft_count_quote(char *command);
char	**ft_check_command(char *command);
void	find_path(t_command *vars, char **envp);
void	find_bin_out(t_command *vars, char **av);
void	find_bin_in(t_command *vars, char **av);
void	ft_find(t_command *vars, char **av, char **envp);

#endif
