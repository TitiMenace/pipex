#ifndef STRUCT_H
# define STRUCT_H

# include "pipex.h"
# include "includes.h"

# include <stdbool.h>

typedef struct	s_cmd
{
	int		close_fd;
	int		fd_in;
	int		fd_out;
	char	*path;
	char	**args;
}				t_cmd;



typedef struct	s_data
{
	bool	here_doc;
	char	**paths;
	char	*file_in;
	int		*pipe_fd;
	char	*file_out;
}				t_data;


#endif
