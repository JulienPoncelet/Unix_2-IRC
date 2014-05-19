/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 11:17:09 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 10:30:27 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

int								ft_bind(int sd, int port)
{
	struct sockaddr_in			sockin;

	sockin.sin_family = FAMILY;
	sockin.sin_port = htons(port);
	sockin.sin_addr.s_addr = htonl(INADDR_ANY);
	ft_bzero(&(sockin.sin_zero), 8);
	if (bind(sd, (struct sockaddr *)&sockin, sizeof(struct sockaddr_in)) == -1)
		return (ft_error("serveur", __FILE__, __LINE__));
	return (0);
}
