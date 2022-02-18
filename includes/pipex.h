/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:50:07 by jwilliam          #+#    #+#             */
/*   Updated: 2022/02/17 12:25:31 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include "../libft/includes/libft.h"

void		sub_process(char **argv, char **envp, int *fd);

void		main_process(char **argv, char **envp, int *fd);

char		**get_path(char **envp);

char		*access_path(char **env_paths, char *cmd);

void		error_func(void);

void		invalid_cmd(void);

void		invalid_args(void);

#endif
