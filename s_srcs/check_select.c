/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 13:27:09 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 13:57:27 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

void						check_select(t_serveur *serveur)
{
	int						i;
	int						flag;

	i = 0;
	while (i < MAX_CLIENT && serveur->select_ret > 0)
	{
		flag = 0;
		if (FD_ISSET(i, &(serveur->fd_read)))
		{
			serveur->tab_fds[i]->fct_read(serveur, i);
			flag = 1;
		}
		if (FD_ISSET(i, &(serveur->fd_write)))
		{
			serveur->tab_fds[i]->fct_write(serveur, i);
			flag = 1;
		}
		if (flag)
			serveur->select_ret--;
		i++;
	}
}
