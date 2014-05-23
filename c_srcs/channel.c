/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 14:47:15 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 15:05:58 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

char						*join(t_client *client)
{
	char					**split;
	char					tmp[1];

	send(client->sd, "2", 1, 0);
	split = ft_strsplit(client->line, " ");
	if (!split[1])
		return (JOIN_ARG);
	send(client->sd, split[1], SIZE, 0);
	recv(client->sd, tmp, 1, 0);
	if (tmp[0] == '0')
		return (JOIN_USE);
	client->chan = split[1];
	return (0);
}

char						*create(t_client *client)
{
	char					**split;
	char					tmp[1];

	send(client->sd, "4", 1, 0);
	split = ft_strsplit(client->line, " ");
	if (!split[1])
		return (NICK_ARG);
	send(client->sd, split[1], SIZE, 0);
	recv(client->sd, tmp, 1, 0);
	if (tmp[0] == '0')
		return (NICK_USE);
	client->chan = split[1];
	return (0);
}

char						*leave(t_client *client)
{
	if (ft_strequ(client->chan, "Home"))
		return (LEAVE_HOME);
	client->chan = "Home";
	return (0);
}

char						*list(t_client *client)
{
	char					buf[SIZE + 1];

	send(client->sd, "5", 1, 0);
	attroff(COLOR_PAIR(2));
	while (recv(client->sd, buf, SIZE, 0))
	{
		if (ft_strequ(buf, "0"))
			break ;
		mvprintw(client->y, 0, "%s\n", buf);
		inc_y(client);
		send(client->sd, "0", 1, 0);
	}
	attron(COLOR_PAIR(2));
	return (0);
}
