/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 14:47:15 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 14:49:11 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

char							*who(t_client *client)
{
	char						buf[SIZE + 1];

	send(client->sd, "6", 1, 0);
	while (recv(client->sd, buf, SIZE, 0))
	{
		if (ft_strequ(buf, "0"))
			break ;
		attroff(COLOR_PAIR(2));
		mvprintw(client->y, 0, "%s\n", buf);
		attron(COLOR_PAIR(2));
		inc_y(client);
	}
	return (0);
}
