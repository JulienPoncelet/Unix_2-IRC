/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 13:16:25 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/21 18:41:50 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void					init_select(t_client *client)
{
	FD_ZERO(&(client->fd_read));
	FD_SET(client->sd, &(client->fd_read));
	FD_SET(0, &(client->fd_read));
}
