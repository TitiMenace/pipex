#include "pipex.h"
#include "struct.h"
#include "includes.h"


void	free_data_paths(t_data *data)
{
	int	i;

	i = 0;
	while (data->paths[i])
	{
		free(data->paths[i]);
		i++;
	}
	free(data->paths[i]);
	free(data->paths);
}




int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac < 5)
		return (1);
	if (!get_files(&data, av, ac))
		return (1);
	if (!set_in_and_out(&data))
	{
		free(data.file_in);
		free(data.file_out);
		return (1);
	}
	get_paths(&data, env); // recup le env | grep PATH
	if (!pipe_loop(ac, av, env, &data))
	{
		free(data.file_in);
		free(data.file_out);
		return (1);
	}
	free_data_paths(&data);	
	free(data.file_in);
	free(data.file_out);
	return (0);
}
