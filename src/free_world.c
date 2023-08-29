
#include "pipex.h"
#include "struct.h"
#include "includes.h"

void	free_cmd_args(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
	{
		free(cmd->args[i]);
		i++;
	}
	free(cmd->args[i]);
	free(cmd->args);
}
