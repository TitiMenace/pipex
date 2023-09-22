/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:35:54 by tschecro          #+#    #+#             */
/*   Updated: 2023/09/22 18:37:38 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "pipex.h"
# include "includes.h"

# include <stdbool.h>

typedef struct s_cmd
{
	int		close_fd;
	int		fd_in;
	int		fd_out;
	char	*path;
	char	**args;
}				t_cmd;

typedef struct s_data
{
	bool	here_doc;
	char	**paths;
	char	*file_in;
	int		*pipe_fd;
	char	*file_out;
}				t_data;

#endif
