
#include "pipex.h"
#include "struct.h"
#include "includes.h"

int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	wordsize(char *str, char *charset)
{
	int	count;

	count = 0;
	while (!is_charset(str[count], charset) && str[count])
		count++;
	return (count + 1);
}

char	*first_word(char **str, char *charset)
{
	int		i;
	char	*word;

	word = malloc((wordsize(*str, charset)) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (!is_charset(**str, charset) && **str)
	{
		word[i] = **str;
		(*str)++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		tab_index;

	tab = malloc(ft_strlen(str) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab_index = 0;
	while (*str)
	{
		while (is_charset(*str, charset) && *str)
			str++;
		if (!*str)
			break ;
		tab[tab_index] = first_word(&str, charset);
		tab_index++;
	}
	tab[tab_index] = NULL;
	return (tab);
}
