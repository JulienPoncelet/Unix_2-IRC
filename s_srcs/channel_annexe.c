/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel_annexe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 15:44:16 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/25 15:44:25 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

int							chan_used(t_serveur *serveur, char *chan)
{
	int						i;

	i = 0;
	while (serveur->channels[i])
	{
		if (ft_strequ(serveur->channels[i], chan))
			return (1);
		i++;
	}
	return (0);
}

void						add_chan(t_serveur *serveur, char *chan)
{
	int						i;

	i = 0;
	while (serveur->channels[i])
		i++;
	serveur->channels[i] = ft_strdup(chan);
	serveur->channels[i + 1] = NULL;
}
