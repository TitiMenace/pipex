#include "pipex.h"
#include "struct.h"
#include "includes.h"

bool	get_files(t_data *data, char **av)
{
	data->file_in = ft_strdup(av[1]);
	if (!data->file_in)
		return (false);
	data->file_out = ft_strdup(av[5]);
	if (!data->file_out)
		return (false);
}
