/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:37:08 by tschecro          #+#    #+#             */
/*   Updated: 2023/09/21 18:40:22 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "struct.h"
#include "includes.h"

void	free_data_paths(t_data *data)
{
	int	i;

	i = 0;
	while (data->paths[i])
	{
		free(data->paths[i]);
		i++;
	}
	free(data->paths[i]);
	free(data->paths);
}

bool	checking_relative_path(char	*str)
{
	if (str[0] == '.' && str[1] == '/')
		return (true);
	else
		return (false);
}

void	check_here_doc(char *str, t_data *data)
{
	if (ft_strcmp(str, "here_doc") == 0)
		data->here_doc = true;
	else
		data->here_doc = false;
}

void	free_fds_and_path(t_data *data)
{
	free(data->file_in);
	free(data->file_out);
	free_data_paths(data);
	exit(1);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac < 5)
		return (1);
	check_here_doc(av[1], &data);
	if (data.here_doc == true && ac < 6)
		return (1);
	if (!get_files(&data, av, ac))
		return (1);
	if (!set_in_and_out(&data, av))
	{
		if (!data.here_doc)
			free(data.file_in);
		free(data.file_out);
		return (1);
	}
	get_paths(&data, env);
	if (!pipe_loop(ac, av, env, &data))
		free_fds_and_path(&data);
	if (!data.here_doc)
		free(data.file_in);
	free(data.file_out);
	return (0);
}
