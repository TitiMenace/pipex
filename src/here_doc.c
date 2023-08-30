
#include "pipex.h"
#include "struct.h"
#include "includes.h"

int	ft_putstr_fd(char *str, int fd)
{
	return (write(fd, str, ft_strlen(str)));
}

int	here_doc(char *limiter)
{
	int		pipe_fd[2];
	pid_t	cpid;
	char	*line;

	if (pipe(pipe_fd) == -1)
		return (-1);
	cpid = fork();
	if (!cpid)
	{
		close(pipe_fd[0]);
		line = get_next_line(0);
		while (line && line[0])
		{
			if (ft_strcmp(line, limiter) == 0)
				break;
			ft_putstr_fd(line, pipe_fd[1]);
			free(line);
			line = get_next_line(0);
		}
		close(pipe_fd[1]);
		free(line);
		exit(0);
	}
	wait(0);
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}	
