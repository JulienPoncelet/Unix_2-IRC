/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_serveur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 10:42:45 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/21 14:38:08 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

t_serveur						*init_serveur(int port)
{
	t_serveur					*serveur;
	int							sd;

	if (!(serveur = (t_serveur *)malloc(sizeof(t_serveur))))
	{
		ft_error("serveur", __FILE__, __LINE__);
		return (NULL);
	}
	if (!(serveur->tab_fds = init_fds()))
	{
		ft_error("serveur", __FILE__, __LINE__);
		return (NULL);
	}
	if ((sd = ft_socket()) == FT_ERROR)
	{
		ft_error("serveur", __FILE__, __LINE__);
		return (NULL);
	}
	serveur->port = port;
	return (init_serveur2(serveur, sd));
}

t_serveur						*init_serveur2(t_serveur *serveur, int sd)
{
	if (ft_bind(sd, serveur->port) == FT_ERROR)
	{
		ft_error("serveur", __FILE__, __LINE__);
		return (NULL);
	}
	if (ft_listen(sd) == FT_ERROR)
	{
		ft_error("serveur", __FILE__, __LINE__);
		return (NULL);
	}
	serveur->tab_fds[sd]->type = FD_SERVEUR;
	serveur->tab_fds[sd]->fct_read = add_client;
	serveur->nicks = (char **)malloc(sizeof(char *) * MAX_CLIENT);
	serveur->nicks[0] = NULL;
	serveur->channels = (char **)malloc(sizeof(char *) * MAX_CLIENT);
	serveur->channels[0] = ft_strdup("Home");
	serveur->channels[1] = NULL;
	return (serveur);
}

int								end_serveur(t_serveur *serveur)
{
	free(serveur->nicks);
	free(serveur->channels);
	free(serveur);
	return (0);
}
