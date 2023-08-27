#include "pipex.h"
#include "struct.h"
#include "includes.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	t_cmd	cmd1;
	t_cmd	cmd2;
	int	fd_in;
	int	fd_out;
	int	pipe_fd[2];
	pid_t	pid_cmd1;
	pid_t	pid_cmd2;

	if (ac != 5)
		return (1);
	if (!get_files(&data, av))
		return (1);
	fd_in = open(data.file_in, O_RDONLY);
	dup2(fd_in, 0);
	close(fd_in);
	get_paths(&data, env); // recup le env | grep PATH
	get_cmd_args(&cmd1, av[2]); // recup le nom de la commande et ses args dans un tab de tab
 	cmd1.path = find_path(&data, cmd1.args[0]); // recup le path exact pour trouver la commande
	if (pipe(pipe_fd) == -1) // utilise un pipe pour communiquer entre les commandes, pas tres clair
		return (0);
	pid_cmd1 = fork();	// creer un process pour exec les commandes dans les enfants
	if (pid_cmd1 == 0)	// suis je dans l'enfant
	{
		//dup le vicieux qui remplace le out par ce qu'il veut 
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		exec_cmd(cmd1.path, env, cmd1.args);
	}
	else
	{
		get_cmd_args(&cmd2, av[3]); // recup le nom de la commande et ses args dans un tab de tab
 		cmd2.path = find_path(&data, cmd2.args[0]); // recup le path exact pour trouver la commande
		fd_out = open(data.file_out, O_RDWR | O_CREAT | O_TRUNC , 0664);
		dup2(fd_out, 1);
		close(fd_out);
		pid_cmd2 = fork();
		
		if (pid_cmd2 == 0)
		{
			close(pipe_fd[1]);
			dup2(pipe_fd[0], 0);
			close(pipe_fd[0]);
			exec_cmd(cmd2.path, env, cmd2.args);
		}
		else
		{
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			waitpid(pid_cmd1, 0, WUNTRACED);
			waitpid(pid_cmd2, 0, WUNTRACED);
			return(0);
		}
	}
}
