/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 13:07:44 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 13:12:39 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

int						client_write(t_serveur *serveur, int cs)
{
	int					ret;

	ret = recv(cs, serveur->tab_fds[cs]->buf_write, SIZE, 0);
	if (ret <= 0)
	{
		close(cs);
		clean_fd(serveur->tab_fds[cs]);
		printf("\n");
	}
	else
		printf("%s\n", serveur->tab_fds[cs]->buf_write);
	return (0);
}
