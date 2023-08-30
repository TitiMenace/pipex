#include "pipex.h"
#include "struct.h"
#include "includes.h"

bool	get_files(t_data *data, char **av, int ac)
{
	if (data->here_doc == false)
	{
		data->file_in = ft_strdup(av[1]);
		if (!data->file_in)
			return (false);
	}
	data->file_out = ft_strdup(av[ac - 1]);
	if (!data->file_out)
		return (false);
	return (true);
}
