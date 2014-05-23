/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 14:47:15 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 14:47:50 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

char						*nick(t_client *client)
{
	char					**split;
	char					tmp[1];

	send(client->sd, "1", 1, 0);
	split = ft_strsplit(client->line, " ");
	if (!split[1])
		return (NICK_ARG);
	send(client->sd, split[1], SIZE, 0);
	recv(client->sd, tmp, 1, 0);
	if (tmp[0] == '0')
		return (NICK_USE);
	client->nick = split[1];
	client->x = ft_strlen(client->chan) + ft_strlen(split[1]) + 5;
	client->curx = client->x;
	return (0);
}
