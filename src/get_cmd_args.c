#include "pipex.h"
#include "struct.h"
#include "includes.h"

bool	get_cmd_args(t_data *data, char *cmd)
{
	data->cmd_args = ft_split(cmd, " \a\b\t\n\v\f\r");
	if (!data->cmd_args)
		return (false);
	return (true);
}


