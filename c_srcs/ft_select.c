/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 13:23:36 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/21 18:43:14 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int						ft_select(t_client *client)
{
	int					ret;
	struct timeval		time;

	init_select(client);
	time.tv_sec = 1;
	time.tv_usec = 0;
	ret = select(client->sd + 1, &(client->fd_read), NULL, NULL, &time);
	if (FD_ISSET(client->sd, &(client->fd_read)))
		read_msg(client);
	if (FD_ISSET(0, &(client->fd_read)))
		return (add_ch(client));
	return (-1);
}

void					read_msg(t_client *client)
{
	char				nick[SIZE + 1];
	char				msg[SIZE + 1];

	ft_bzero(nick, SIZE);
	ft_bzero(msg, SIZE);
	recv(client->sd, nick, SIZE, 0);
	recv(client->sd, msg, SIZE, 0);
	attroff(COLOR_PAIR(2));
	mvprintw(client->y, 0, "[%s] %s: %s\n", client->chan, nick, msg);
	inc_y(client);
	attron(COLOR_PAIR(2));
	mvprintw(client->y, 0, "[%s] %s: %s", client->chan, client->nick,
		client->buf);
	refresh();
}
