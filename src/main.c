#include "pipex.h"
#include "struct.h"
#include "includes.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	t_cmd	cmd;

	(void)ac;
	int	pipe_fd[2];
	pid_t	pid;
	get_paths(&data, env); // recup le env | grep PATH
	get_cmd_args(&cmd, av[1]); // recup le nom de la commande et ses args dans un tab de tab
 	cmd.path = find_path(&data, cmd.args[0]); // recup le path exact pour trouver la commande
	if (pipe(pipe_fd) == -1) // utilise un pipe pour communiquer entre les commandes, pas tres clair
		return (0);
	pid = fork();	// creer un process pour exec les commandes dans les enfants
	if (pid == 0)	// suis je dans l'enfant
	{
		//dup le vicieux qui remplace le out par ce qu'il veut 
		dup2(pipe_fd[1], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exec_cmd(cmd.path, env, cmd.args);
	}
	else
	{
		return(1);
	}
}
