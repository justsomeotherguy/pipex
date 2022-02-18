/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:13:07 by jwilliam          #+#    #+#             */
/*   Updated: 2022/02/16 12:12:25 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
Function used to parse the **envp arguments from the main function and
retrieve the PATH line

Places all possible listed paths in the PATH line into a string double array.
*/
char	**get_path(char **envp)
{
	int		index;
	char	**paths;

	index = 0;
	while (ft_strncmp(envp[index], "PATH=", 5) != 0)
		index++;
	paths = ft_split(envp[index] + 5, ':');
	return (paths);
}
