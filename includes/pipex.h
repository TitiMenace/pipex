/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:48:15 by tschecro          #+#    #+#             */
/*   Updated: 2023/09/21 19:48:38 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "includes.h"
# include "struct.h"

//Functions from file : get_cmd.c
bool	str_check(char *s1, char *s2);

bool	get_paths(t_data *data, char **env);

char	*find_path(t_data *data, char *str);

void	exec_cmd(char *path_cmd, char **env, char **args);

//Functions from file : utils.c
int		ft_strcmp(char *s1, char *s2);

//Functions from file : strjoin.c
char	*cmd_join(char *s1, char *s2);

//Functions from file : free_world.c
void	free_cmd_args(t_cmd *cmd);

//Functions from file : here_doc.c
int		ft_strncmp(char *s1, char *s2, int len);

int		ft_putstr_fd(char *str, int fd);

void	child_here_doc(int *pipe_fd, char *limiter);

int		here_doc(char *limiter);

//Functions from file : pipe_loop_utils.c
void	init_path_before_fork(char **av, t_cmd *cmd, t_data *data, int *i);

bool	free_no_path(t_cmd *cmd, pid_t *cmds_pids);

void	child_exec(t_cmd *cmd, char **env);

void	parent_exec(int *i, t_cmd *cmd);

void	exec_fork(pid_t *cmds_pids, int *i, t_cmd *cmd, char **env);

//Functions from file : get_files.c
bool	get_files(t_data *data, char **av, int ac);

//Functions from file : split.c
int		is_charset(char c, char *charset);

int		wordsize(char *str, char *charset);

char	*first_word(char **str, char *charset);

char	**ft_split(char *str, char *charset);

//Functions from file : new_pipe.c
bool	pipe_init(t_cmd *cmd, int *pipe_fd, int i, int cmd_nb);

//Functions from file : get_cmd_utils.c
char	*ft_strdup(const char *s);

int		ft_strlen(char *str);

int		ft_str_is_find(char *s1, char *s2);

//Functions from file : get_next_line.c
char	*ft_fill_line(char *buffer, int fd, char **remain);

char	*get_next_line(int fd);

//Functions from file : get_cmd_args.c
bool	get_cmd_args(t_cmd *cmd, char *str);

//Functions from file : pipe_loop.c
void	wait_pids(pid_t *cmds_pids, int command_nb);

pid_t	*init_pid(int command_nb);

bool	set_before_fork(int *i, char **av, pid_t *cmds_pids, t_cmd *cmd);

void	command_here_doc(t_data *data, char **av, int *command_nb);

bool	pipe_loop(int ac, char **av, char **env, t_data *data);

//Functions from file : dup_pipe.c
void	dup_pipes(t_cmd *cmd);

void	close_fds(t_cmd *cmd);

//Functions from file : main.c
void	free_data_paths(t_data *data);

bool	checking_relative_path(char *str);

void	check_here_doc(char *str, t_data *data);

void	free_fds_and_path(t_data *data);

//Functions from file : get_next_line_utils.c
char	*ft_strndup(char *str);

int		check_buff(char *buffer, char c);

char	*ft_strjoin(char *remain, char *buffer);

//Functions from file : set_in_and_out.c
bool	set_no_here_doc(int *file_in, int *file_out, t_data *data);

bool	set_here_doc(int *file_in, int *file_out, t_data *data, char **av);

bool	set_in_and_out(t_data *data, char **av);

#endif
