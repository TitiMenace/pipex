#include "pipex.h"
#include "struct.h"
#include "includes.h"

bool	get_cmd_args(t_cmd *cmd, char *str)
{
	cmd->args = ft_split(str, " \a\b\t\n\v\f\r");
	if (!cmd->args)
		return (false);
	return (true);
}
