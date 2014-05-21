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

	ft_putstr_fd(client->nick, client->sd);
	recv(client->sd, tmp, 1, 0);
	ft_putstr_fd(client->line, client->sd);
	recv(client->sd, tmp, 1, 0);
	return (0);
}
