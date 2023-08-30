/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titilamenace <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:45:15 by titilamenace      #+#    #+#             */
/*   Updated: 2023/08/30 19:18:40 by titilamenace     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "includes.h"
# include "struct.h"

//Functions from file : here_doc.c
int	ft_putstr_fd(char *str, int fd);

int		here_doc(char *limiter);

//Functions from file : get_cmd_args.c
bool	get_cmd_args(t_cmd *cmd, char *str);

//Functions from file : main.c
void	free_data_paths(t_data *data);

bool	checking_relative_path(char *str);

void	check_here_doc(char *str, t_data *data);

//Functions from file : get_files.c
bool	get_files(t_data *data, char **av, int ac);

//Functions from file : free_world.c
void	free_cmd_args(t_cmd *cmd);

//Functions from file : get_next_line.c
char	*ft_fill_line(char *buffer, int fd, char **remain);

char	*get_next_line(int fd);

//Functions from file : dup_pipe.c
void	dup_pipes(t_cmd *cmd);

void	close_fds(t_cmd *cmd);

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

//Functions from file : pipe_loop.c
void	wait_pids(pid_t *cmds_pids, int command_nb);

pid_t	*init_pid(int command_nb);

bool	pipe_loop(int ac, char **av, char **env, t_data *data);

//Functions from file : utils.c
int		ft_strcmp(char *s1, char *s2);

//Functions from file : set_in_and_out.c
bool	set_in_and_out(t_data *data, char **av);

//Functions from file : new_pipe.c
bool	pipe_init(t_cmd *cmd, int *pipe_fd, int i, int cmd_nb);

//Functions from file : get_cmd.c
bool	str_check(char *s1, char *s2);

bool	get_paths(t_data *data, char **env);

char	*find_path(t_data *data, char *str);

void	exec_cmd(char *path_cmd, char **env, char **args);

//Functions from file : get_next_line_utils.c
char	*ft_strndup(char *str);

int		check_buff(char *buffer, char c);

char	*ft_strjoin(char *remain, char *buffer);

#endif
