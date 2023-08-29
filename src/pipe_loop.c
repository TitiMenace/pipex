#include "pipex.h"
#include "struct.h"
#include "includes.h"

pid_t	*init_pid(int command_nb)
{
	pid_t	*tab;

	tab = malloc(sizeof(pid_t) * command_nb);
	if (!tab)
		return (NULL);
	return (tab);
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
	cmds_pids = init_pid(command_nb);
	av+=2;
	while (i < command_nb)
	{	
		get_cmd_args(&cmd, av[i]);
		cmd.path = find_path(data, cmd.args[0]);
		if (!pipe_init(&cmd, pipe_fd, i, command_nb))
			return (false);
		cmds_pids[i] = fork();
		if (cmds_pids[i] == 0)
		{
			dup_pipes(&cmd);
			close_fds(&cmd);	
			exec_cmd(cmd.path, env, cmd.args);
			exit(1);
		}
		else
		{
			if (i)
				close(cmd.fd_in);
			waitpid(cmds_pids[i], 0, WUNTRACED);	
			i++;
		}
		free_cmd_args(&cmd);
		free(cmd.path);
	}
	free(cmds_pids);
	return (true);
}
