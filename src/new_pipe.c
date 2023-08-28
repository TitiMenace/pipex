#include "pipex.h"
#include "struct.h"
#include "includes.h"

bool	pipe_init(t_cmd *cmd, int *pipe_fd, int	i, int cmd_nb)
{
	if (i == 0)
	{
		if (pipe(pipe_fd) == -1)
			return (false);
		cmd->fd_in = -1;
		cmd->fd_out = pipe_fd[1];
		close(pipe_fd[0]);
	}
	else if (i < cmd_nb)
	{
		cmd->fd_in = pipe_fd[0];
		cmd->fd_out = -1;
		close(pipe_fd[0]);
	}
	else
	{
		if (pipe(pipe_fd) == -1)
			return (false);
		cmd->fd_in = pipe_fd[0];
		cmd->fd_out = pipe_fd[1];
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	return(true);
}
