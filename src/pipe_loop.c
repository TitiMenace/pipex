/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:40:54 by tschecro          #+#    #+#             */
/*   Updated: 2023/09/21 19:37:34 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "struct.h"
#include "includes.h"

void	wait_pids(pid_t	*cmds_pids, int command_nb)
{
	int	i;

	i = 0;
	while (i < command_nb)
	{
		waitpid(cmds_pids[i], 0, WUNTRACED);
		i++;
	}
}

pid_t	*init_pid(int command_nb)
{
	pid_t	*tab;

	tab = malloc(sizeof(pid_t) * command_nb);
	if (!tab)
		return (NULL);
	return (tab);
}

bool	set_before_fork(int *i, char **av, pid_t *cmds_pids, t_cmd *cmd)
{
	if (av[*i][0] == '\0')
	{
		free(cmds_pids);
		return (false);
	}
	if (!get_cmd_args(cmd, av[*i]))
	{
		free(cmds_pids);
		return (false);
	}
	return (true);
}

void	command_here_doc(t_data *data, char **av, int *command_nb)
{
	if (data->here_doc == true)
	{
		av += 1;
		(*command_nb) -= 1;
	}
}

bool	pipe_loop(int ac, char **av, char **env, t_data *data)
{
	int		i;
	int		command_nb;
	pid_t	*cmds_pids;
	t_cmd	cmd;
	int		pipe_fd[2];

	command_nb = ac - 3;
	i = 0;
	command_here_doc(data, av, &command_nb);
	cmds_pids = init_pid(command_nb);
	av += 2;
	while (i < command_nb)
	{	
		if (!set_before_fork(&i, av, cmds_pids, &cmd))
			return (false);
		init_path_before_fork(av, &cmd, data, &i);
		if (!free_no_path(&cmd, cmds_pids))
			return (false);
		if (!pipe_init(&cmd, pipe_fd, i, command_nb))
			return (false);
		exec_fork(cmds_pids, &i, &cmd, env);
	}
	wait_pids(cmds_pids, command_nb);
	free(cmds_pids);
	return (true);
}
