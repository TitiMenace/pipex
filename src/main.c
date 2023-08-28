#include "pipex.h"
#include "struct.h"
#include "includes.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac < 5)
		return (1);
	if (!get_files(&data, av, ac))
		return (1);
	if (!set_in_and_out(&data))
		return (1);
	get_paths(&data, env); // recup le env | grep PATH
	if (!pipe_loop(ac, av, env, &data))
		return (1);
	return (0);
}
