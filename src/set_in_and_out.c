
#include "pipex.h"
#include "struct.h"
#include "includes.h"

bool	set_in_and_out(t_data *data)
{
	int file_in;
	int	file_out;

	file_in = open(data->file_in, O_RDONLY);
	if (file_in == -1)
		return (false);
	file_out = open(data->file_out, O_RDWR | O_CREAT, 0664);
	if (file_out == -1)
		return (false);
	dup2(file_in, 0);
	close(file_in);
	dup2(file_out, 1);
	close(file_out);
	return (true);
}
