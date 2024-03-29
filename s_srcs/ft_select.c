/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 13:23:36 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/21 18:43:14 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

int						ft_select(t_serveur *serveur)
{
	int					ret;

	ret = select(serveur->max + 1, &(serveur->fd_read), &(serveur->fd_write),
			NULL, NULL);
	if (ret == -1)
		return (FT_ERROR);
	serveur->select_ret = ret;
	return (0);
}
