/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:37:42 by tschecro          #+#    #+#             */
/*   Updated: 2023/09/21 19:37:44 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "struct.h"
#include "includes.h"

bool	get_cmd_args(t_cmd *cmd, char *str)
{
	cmd->args = ft_split(str, " \a\b\t\n\v\f\r");
	if (!cmd->args)
		return (false);
	return (true);
}
