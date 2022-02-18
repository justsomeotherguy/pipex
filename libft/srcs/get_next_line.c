/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:05:28 by jwilliam          #+#    #+#             */
/*   Updated: 2021/11/10 11:32:01 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

/*
Function to read the line, passes buffer through the read function limited by
defined buffer size. Gets the characters read and appends to the *store
variable.
*/
static char	*process_line(int fd, char *buffer, char *store)
{
	int				read_result;
	char			*temp_str;

	read_result = 1;
	while (read_result != '\0')
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result == -1)
			return (0);
		else if (read_result == 0)
			break ;
		buffer[read_result] = '\0';
		if (!store)
			store = ft_strdup("");
		temp_str = store;
		store = ft_strjoin(temp_str, buffer);
		free(temp_str);
		temp_str = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (store);
}

/*
Function that reads the line and creates a substring if a new line character
is found.
*/
static char	*make_line(char *str)
{
	size_t			index;
	char			*ret;

	index = 0;
	while (str[index] != '\n' && str[index] != '\0')
		index++;
	if (str[index] == '\0' || str[1] == '\0')
		return (0);
	ret = ft_substr(str, index + 1, ft_strlen(str) - index);
	if (*ret == '\0')
	{
		free(ret);
		ret = NULL;
	}
	str[index + 1] = '\0';
	return (ret);
}

/*
Main get_next_line function, takes the input from the file descriptor and
parses it through a function that reads the file contents by the amount of
characters defined in the BUFFER_SIZE. When a new line is encountered, it will
end the string and create a new one.
*/
char	*get_next_line(int fd)
{
	char			*ret;
	char			*buffer;
	static char		*store;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	ret = process_line(fd, buffer, store);
	free(buffer);
	buffer = NULL;
	if (!ret)
		return (NULL);
	store = make_line(ret);
	return (ret);
}
