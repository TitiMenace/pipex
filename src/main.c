#include "pipex.h"
#include "struct.h"
#include "includes.h"

int	main(int ac, char **av, char **env)
{
	(void)av;
	(void)ac;
	t_data	data;
	char *cmd;

	get_paths(&data, env);
	get_cmd_args(&data, av[1]);
 	cmd = find_path(&data, data.cmd_args[0]);
	exec_cmd(cmd, env, &data);
	
}
