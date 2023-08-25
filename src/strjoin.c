#include "pipex.h"
#include "struct.h"
#include "includes.h"

char	*cmd_join(char *s1, char *s2)
{
	char	*str;
	int		i;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i++] = *s1;
		s1++;
	}
	str[i] = '/';
	i++;
	while (*s2)
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = 0;
	return (str);
}
