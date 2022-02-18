/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:34:59 by jwilliam          #+#    #+#             */
/*   Updated: 2022/02/17 12:50:46 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

/*
The Main Function of the pipex program. 

First checks the argc count, if it is not equal to 5 which is the improper
usage for the pipex program, it will display generic text error and exit with
code 1.

Function creates a pipe using the pipe() function which establishes
a pair of file descriptors in an array. The pair of file descriptors created
using pipe will be used, one as a read source and the other as a write
destination.

fork() creates a new process instance, the child process is an exact duplicate
of the current running process with its own unique process ID. If the return
value of fork() is 0, it is the process ID of the child, when it is finished,
the fork() function will return the value of the parent process instead.

During the time the child function exists, it will pass to the sub_process
function which handles the read end of the files/commands.

waitpid() uses the child process ID to create a wait call for the running
process and will advance in the function when the process has successfully
finished. WNOHANG checks that the status is always immediately accessible
otherwise it will force end the process.

main_process handles the write end of the files/commands.
*/
int	main(int argc, char **argv, char **envp)
{
	int			fd[2];
	int			process_id;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error_func();
		process_id = fork();
		if (process_id == -1)
			error_func();
		if (process_id == 0)
			sub_process(argv, envp, fd);
		if (waitpid(process_id, NULL, WNOHANG) < 0)
			error_func();
		main_process(argv, envp, fd);
	}
	else if (argc != 5)
		invalid_args();
	return (0);
}
