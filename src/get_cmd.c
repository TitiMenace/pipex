#include "pipex.h"
#include "struct.h"
#include "includes.h"

bool	str_check(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s2[i])
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
		if (!s1[i])
			return (false);
	}
	return (true);
}

bool	get_paths(t_data *data, char **env)
{	
	int i;

	i = 0;
	while (*env)
	{
		if (str_check(env[i], "PATH="))
			break;
		i++;
	}
	if (!env[i])
		return (false);
	else
	{
		data->paths = ft_split(env[i], ":");
		if (!data->paths)
			return (false);
		return (true);
	}
}

char	*find_path(t_data *data, char *str)
{	
	char	*path;
	int		i;

	i = 0;
	while (data->paths[i])
	{
		path = cmd_join(data->paths[i], str);
	if (!path)
			return (NULL);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}
	
void	exec_cmd(char *path_cmd, char **env, char **args)
{
	execve(path_cmd, args, env);
}
