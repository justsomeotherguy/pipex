/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:37:27 by jwilliam          #+#    #+#             */
/*   Updated: 2022/02/16 12:12:55 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
Function breaks down the "PATH=" line from the **envp argument and the command
received from the **argv argument received from the main file and tries to
determine if the command can be properly accessed using all the possible
paths in the PATHS str double array. 

If the commands are not valid, it will pass to the invalid_cmd() function to 
return an error.
*/
char	*access_path(char **env_paths, char *cmd)
{
	int		index;
	char	*temp_path;
	char	*exe_path;

	index = 0;
	while (env_paths[index])
	{
		temp_path = ft_strjoin(env_paths[index], "/");
		exe_path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (access(exe_path, F_OK) == 0)
			return (exe_path);
		free (exe_path);
		index++;
	}
	invalid_cmd();
	return (0);
}
