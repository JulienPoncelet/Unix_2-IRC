/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 17:34:23 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/21 18:19:37 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int								add_ch(t_client *client)
{
	static char					*buf = NULL;
	int							key;
	int							type;

	if (!buf)
	{
		client->curx = ft_strlen(client->nick) + 2;
		buf = ft_strnew(SIZE + 1);
	}
	key = getch();
	buf = use_key(key, buf, client);
	mvprintw(client->y, client->x, "%s", buf);
	delch();
	wmove(client->win, client->y, client->curx);
	refresh();
	if (key == 10)
	{
		printw("\n");
		if (client->y < client->maxy - 1)
			client->y++;
		client->curx = client->x;
		client->line = ft_strdup(buf);
		type = get_type(buf);
		ft_bzero(buf, SIZE);
		return (type);
	}
	return (-1);
}
