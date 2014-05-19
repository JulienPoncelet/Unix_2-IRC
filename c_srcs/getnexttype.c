/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnexttype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:29:42 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 16:35:59 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int							getnexttype(int sson, char **line)
{
	char					**split;
	int						type;

	*line = get_next_cmd();
	split = ft_strsplit(*line, " ");
	type = get_type(split[0]);
	return (type);
	(void)sson;
}

char						*get_next_cmd(void)
{
	int						key;
	char					*buf;
	int						i;

	buf = ft_strnew(4096 + 1);
	i = 0;
	while ((key = getch()) != 10 && i < 4096)
	{
		if (key > 31 && key != 127)
		{
			printw("%c", key);
			buf[i] = key;
			i++;
		}
		if (key == 127)
			delch();
	}
	printw("\n");
	return (buf);
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
