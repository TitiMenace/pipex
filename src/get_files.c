/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:39:29 by tschecro          #+#    #+#             */
/*   Updated: 2023/09/21 19:39:33 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "struct.h"
#include "includes.h"

bool	get_files(t_data *data, char **av, int ac)
{
	if (data->here_doc == false)
	{
		data->file_in = ft_strdup(av[1]);
		if (!data->file_in)
			return (false);
	}
	data->file_out = ft_strdup(av[ac - 1]);
	if (!data->file_out)
		return (false);
	return (true);
}
