/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_client.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 20:10:06 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 16:36:03 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

t_client						*init_client(char *addr, int port)
{
	t_client					*client;

	if (!(client = (t_client *)malloc(sizeof(t_client))))
	{
		ft_error("client", __FILE__, __LINE__);
		return (NULL);
	}
	if ((client->sd = ft_socket()) == FT_ERROR)
	{
		ft_error("client", __FILE__, __LINE__);
		return (NULL);
	}
	if ((ft_connect(client->sd, addr, port)) == FT_ERROR)
	{
		ft_error("client", __FILE__, __LINE__);
		return (NULL);
	}
	client->addr = ft_strdup(addr);
	client->port = port;
	client->nick = "Anonymus";
	return (client);
}

void							end_client(t_client *client)
{
	close(client->sd);
	free(client->addr);
	free(client);
}