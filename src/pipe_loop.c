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
		if (av[i][0] == '\0')
		{
			free(cmds_pids);
			return (false);
		}
		if (!get_cmd_args(&cmd, av[i]))
		{
			free(cmds_pids);
			return (false);
		}
		if (!checking_relative_path(av[i]))
			cmd.path = find_path(data, cmd.args[0]);
		else
			cmd.path = ft_strdup(av[i]);
		if (!cmd.path)
		{
			free(cmds_pids);
			free_cmd_args(&cmd);
			dprintf(2, "cat: pipileon: Aucun fichier ou dossier de ce type\nnotexistingcmd : commande introuvable\n");
			return (false);
		}
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
			i++;
		}
		free_cmd_args(&cmd);
		free(cmd.path);
	}
	wait_pids(cmds_pids, command_nb);	
	free(cmds_pids);
	return (true);
}
