/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_socket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 10:44:31 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 14:10:09 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int							ft_socket(void)
{
	struct protoent			*proto;
	int						sd;

	proto = getprotobyname("tcp");
	if (!proto)
		return (ft_error("serveur", __FILE__, __LINE__));
	sd = socket(DOMAIN, TYPE, proto->p_proto);
	if (sd == -1)
		return (ft_error("serveur", __FILE__, __LINE__));
	return (sd);
}
