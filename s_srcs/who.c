/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 14:47:15 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 14:49:11 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

char							*who(t_serveur *serveur, int cs)
{
	int							i;

	i = 0;
	while (i < MAX_CLIENT)
	{
		if (i == cs || is_valid(serveur, cs, i))
			send(cs, serveur->tab_fds[i]->nick, SIZE, 0);
		i++;
	}
	send(cs, "0", SIZE, 0);
	return (0);
}
