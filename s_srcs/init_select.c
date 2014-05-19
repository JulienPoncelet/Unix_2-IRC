/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 13:16:25 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 13:30:33 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

void					init_select(t_serveur *serveur)
{
	int					i;

	i = 0;
	serveur->max = 0;
	FD_ZERO(&(serveur->fd_read));
	FD_ZERO(&(serveur->fd_write));
	while (i < MAX_CLIENT)
	{
		if (serveur->tab_fds[i]->type != FD_FREE)
		{
			FD_SET(i, &(serveur->fd_read));
			if (ft_strlen(serveur->tab_fds[i]->buf_write) > 0)
				FD_SET(i, &(serveur->fd_write));
			serveur->max = MAX(serveur->max, i);
		}
		i++;
	}
}
