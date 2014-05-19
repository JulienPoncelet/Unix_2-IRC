/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnexttype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:29:42 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 15:08:17 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int							getnexttype(int sson, char **line)
{
	char					**split;
	int						type;

	if (get_next_line(sson, line) == -1)
		return (ft_error("client", __FILE__, __LINE__));
	split = ft_strsplit(*line, " ");
	type = get_type(split[0]);
	return (type);
}

int							get_type(char *cmd)
{
	int						i;
	static char				*type_cmd[TYPE_SIZE] = CMD;
	static int				type_enum[TYPE_SIZE] = TYPE_ENUM;

	if (!cmd)
		return (-1);
	if (cmd[0] != '/')
		return (MSG);
	if (ft_strequ(cmd, "/quit"))
		return (QUIT);
	i = 0;
	while (i < TYPE_SIZE)
	{
		if (ft_strequ(cmd, type_cmd[i]))
			return (type_enum[i]);
		i++;
	}
	return (WRONG);
}
