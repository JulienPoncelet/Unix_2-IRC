/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 11:17:09 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 14:14:40 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int								ft_connect(int sd, char *addr, int port)
{
	struct sockaddr_in			sockin;

	sockin.sin_family = FAMILY;
	sockin.sin_port = htons(port);
	sockin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sd, (struct sockaddr *)&sockin, sizeof(sockin)) == -1)
		return (ft_error("client", __FILE__, __LINE__));
	return (0);
}
