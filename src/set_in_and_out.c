/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_and_out.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:04:16 by tschecro          #+#    #+#             */
/*   Updated: 2023/09/21 18:37:01 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "struct.h"
#include "includes.h"

bool	set_no_here_doc(int	*file_in, int *file_out, t_data *data)
{
	*file_in = open(data->file_in, O_RDONLY);
	if (*file_in == -1)
		return (false);
	*file_out = open(data->file_out, O_RDWR | O_CREAT, 0664);
	if (*file_out == -1)
	{
		close(*file_in);
		return (false);
	}
	return (true);
}

bool	set_here_doc(int *file_in, int *file_out, t_data *data, char **av)
{
	*file_in = here_doc(av[2]);
	if (*file_in == -1)
		return (false);
	*file_out = open(data->file_out, O_RDWR | O_CREAT | O_APPEND, 0664);
	if (*file_out == -1)
	{
		close(*file_in);
		return (false);
	}
	return (true);
}

bool	set_in_and_out(t_data *data, char **av)
{
	int	file_in;
	int	file_out;

	if (data->here_doc == false)
	{
		if (!set_no_here_doc(&file_in, &file_out, data))
			return (false);
	}
	else
	{
		if (!set_here_doc(&file_in, &file_out, data, av))
			return (false);
	}
	dup2(file_in, 0);
	close(file_in);
	dup2(file_out, 1);
	close(file_out);
	return (true);
}
