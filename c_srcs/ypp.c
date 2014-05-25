/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ypp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 15:41:30 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/25 15:41:31 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void							inc_y(t_client *client)
{
	int							len;

	len = ft_strlen(client->chan) + ft_strlen(client->nick) +
		ft_strlen(client->buf) + 4;
	while (len)
	{
		YPP(client->y, client->maxy - 1);
		len = len / client->maxx;
	}
}
