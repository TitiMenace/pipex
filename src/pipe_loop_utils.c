/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_loop_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:34:28 by tschecro          #+#    #+#             */
/*   Updated: 2023/09/21 19:40:14 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "struct.h"
#include "includes.h"

void	init_path_before_fork(char **av, t_cmd *cmd, t_data *data, int *i)
{
	if (!checking_relative_path(av[*i]))
		cmd->path = find_path(data, cmd->args[0]);
	else
		cmd->path = ft_strdup(av[*i]);
}

bool	free_no_path(t_cmd *cmd, pid_t *cmds_pids)
{
	if (!cmd->path)
	{
		free(cmds_pids);
		free_cmd_args(cmd);
		return (false);
	}
	return (true);
}

void	child_exec(t_cmd *cmd, char **env)
{
	dup_pipes(cmd);
	close_fds(cmd);
	exec_cmd(cmd->path, env, cmd->args);
	exit(1);
}

void	parent_exec(int *i, t_cmd *cmd)
{	
	if (*i)
		close(cmd->fd_in);
	(*i)++;
}

void	exec_fork(pid_t *cmds_pids, int *i, t_cmd *cmd, char **env)
{
	cmds_pids[*i] = fork();
	if (cmds_pids[*i] == 0)
		child_exec(cmd, env);
	else
		parent_exec(i, cmd);
	free_cmd_args(cmd);
	free(cmd->path);
}
