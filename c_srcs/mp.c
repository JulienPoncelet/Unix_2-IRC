/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 14:47:15 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/25 15:37:06 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

char						*mp(t_client *client)
{
	char					**split;
	char					tmp[1];

	send(client->sd, "7", 1, 0);
	split = ft_strsplit(client->line, " ");
	if (!split[1] || !split[2])
	{
		send(client->sd, "0", SIZE, 0);
		return (MP_ARG);
	}
	send(client->sd, split[1], SIZE, 0);
	recv(client->sd, tmp, 1, 0);
	send(client->sd, get_msg(split), SIZE, 0);
	recv(client->sd, tmp, 1, 0);
	if (tmp[0] == '0')
		return (MP_NICK);
	return (0);
}

char						*get_msg(char **split)
{
	char					*msg;
	int						i;

	msg = ft_strdup(split[2]);
	i = 3;
	while (split[i])
	{
		msg = ft_strjoin(msg, " ");
		msg = ft_strjoin(msg, split[i]);
		i++;
	}
	return (msg);
}
