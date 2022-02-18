/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:06:14 by jwilliam          #+#    #+#             */
/*   Updated: 2022/02/17 13:18:13 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
The main_process is used to handle the write end of the pipex function.

open() accesses the input file and establishes it as a new file descriptor.

In the main_function, if the file does not exist, it will create the file
to output to with appropriate permissions.

dup2() is used to swap the file descriptors from the initial pipe() function
to the newly made file descriptor with the previous open() function.

It is necessary to use the close() function to end accessing finished/unwanted
file descriptors so that other functions requiring inputs from 
file descriptors will not be waiting on these and not able to 
finish the process.

After breaking down the envp input and argv inputs, it is passed to the 
execve() function which attempts to create a new process using the paths and
commands with possible arguments/flags.
*/
void	main_process(char **argv, char **envp, int *fd)
{
	int		fileout;
	char	*exe_path;
	char	**env_path;
	char	**cmd_split;

	fileout = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (dup2(fd[0], STDIN_FILENO) < 0)
		error_func();
	close(fd[0]);
	if (dup2(fileout, STDOUT_FILENO) < 0)
		error_func();
	close(fd[1]);
	close(fileout);
	env_path = get_path(envp);
	cmd_split = ft_split(argv[3], ' ');
	exe_path = access_path(env_path, cmd_split[0]);
	if (execve(exe_path, cmd_split, envp) == -1)
		error_func();
}
