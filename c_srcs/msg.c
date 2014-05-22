/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 14:16:50 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/21 18:43:14 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

char						*msg(t_client *client)
{
	char					tmp[1];

	send(client->sd, "0", 1, 0);
	send(client->sd, client->nick, SIZE, 0);
	recv(client->sd, tmp, 1, 0);
	send(client->sd, client->line, SIZE, 0);
	recv(client->sd, tmp, 1, 0);
	return (0);
}
