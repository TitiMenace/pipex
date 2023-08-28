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
	while (i <= command_nb)
	{	
		dprintf(2, "yes : %d\n", i);
		get_cmd_args(&cmd, av[i + 1]);
		cmd.path = find_path(data, cmd.args[0]);
		cmds_pids[i] = fork();
		if (cmds_pids == 0)
		{
			if (!pipe_init(&cmd, pipe_fd, i, command_nb ))
				return (false);
			dup_pipes(&cmd);
			exec_cmd(cmd.path, env, cmd.args);
		}
		else
			waitpid(cmds_pids[i], 0, WUNTRACED);	
		i++;
	}
	return (true);
}
