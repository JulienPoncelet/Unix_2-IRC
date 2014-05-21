/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnexttype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:29:42 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/21 18:43:14 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

char					*use_key(int key, char *buf, t_client *client)
{
	if (key > 31 && key < 127)
	{
		buf = add_to_buf(buf, client->curx - client->x, key);
		client->curx++;
	}
	if (key == KEY_RIGHT && client->x + ft_strlen(buf) > client->curx)
		client->curx++;
	if (key == KEY_LEFT && client->x != client->curx)
		client->curx--;
	if (key == 127 && client->x != client->curx)
	{
		buf = del_from_buf(buf, client->curx - client->x - 1);
		client->curx--;
	}
	return (buf);
}

char						*add_to_buf(char *buf, int i, int key)
{
	char					tmp;
	
	while (buf[i])
	{
		tmp = buf[i];
		buf[i] = key;
		key = tmp;
		i++;
	}
	tmp = buf[i];
	buf[i] = key;
	key = tmp;
	return (buf);
}

char						*del_from_buf(char *buf, int i)
{
	while (buf[i])
	{
		buf[i] = buf[i + 1];
		i++;
	}
	return (buf);
}



int							get_type(char *cmd)
{
	int						i;
	static char				*type_cmd[TYPE_SIZE] = CMD;
	static int				type_enum[TYPE_SIZE] = TYPE_ENUM;

	i = 0;
	while(cmd[i] && cmd[i] != ' ' && cmd[i] != '\n')
		i++;
	cmd[i] = 0;
	if (!cmd || cmd[0] == '\n')
		return (-2);
	if (cmd[0] != '/')
		return (MSG);
	if (ft_strequ(cmd, "/quit"))
		return (QUIT);
	i = 0;
	while (i < TYPE_SIZE)
	{
		if (ft_strequ(cmd, type_cmd[i]))
			return (type_enum[i + 1]);
		i++;
	}
	return (WRONG);
}
