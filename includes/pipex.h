/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titilamenace <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:33:57 by titilamenace      #+#    #+#             */
/*   Updated: 2023/08/25 21:34:24 by titilamenace     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "struct.h"
#include "includes.h"



//Functions from file : get_cmd_args.c
bool	get_cmd_args(t_data *data, char *cmd);

//Functions from file : main.c
//Functions from file : strjoin.c
char	*cmd_join(char *s1, char *s2);

//Functions from file : get_cmd_utils.c
char	*ft_strdup(const char *s);

int		ft_strlen(char *str);

int		ft_str_is_find(char *s1, char *s2);

//Functions from file : split.c
int		is_charset(char c, char *charset);

int		wordsize(char *str, char *charset);

char	*first_word(char **str, char *charset);

char	**ft_split(char *str, char *charset);

//Functions from file : get_cmd.c
bool	str_check(char *s1, char *s2);

bool	get_paths(t_data *data, char **env);

char	*find_path(t_data *data, char *cmd);

void	exec_cmd(char *path_cmd, char **env, t_data *data);

#endif
