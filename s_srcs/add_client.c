/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 12:54:36 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 13:57:23 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

int							add_client(t_serveur *serveur, int sd)
{
	int						cs;
	struct sockaddr_in		csin;

	if ((cs = ft_accept(sd)) == FT_ERROR)
		return (ft_error("serveur", __FILE__, __LINE__));
	printf("New client #%d from %s:%d\n", cs,
			inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
	clean_fd(serveur->tab_fds[cs]);
	serveur->tab_fds[cs]->type = FD_CLIENT;
	serveur->tab_fds[cs]->fct_read = client_read;
	serveur->tab_fds[cs]->fct_write = client_write;
	return (0);
}
