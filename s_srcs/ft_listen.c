/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:55:06 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 10:30:40 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

int							ft_listen(int sd)
{
	if (listen(sd, BACKLOG) == -1)
		return (ft_error("serveur", __FILE__, __LINE__));
	return (0);
}
