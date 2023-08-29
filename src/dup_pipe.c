
#include "pipex.h"
#include "struct.h"
#include "includes.h"

void	dup_pipes(t_cmd *cmd)
{
	if (cmd->fd_in != -1)
	{
		dup2(cmd->fd_in, 0);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != -1)
	{
		dup2(cmd->fd_out, 1);
		close(cmd->fd_out);
	}
}

void	close_fds(t_cmd *cmd)
{
	if (cmd->close_fd != -1)
		close(cmd->close_fd);
}
