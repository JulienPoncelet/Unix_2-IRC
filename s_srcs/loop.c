/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 10:45:29 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 13:57:51 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

int								loop(t_serveur *serveur)
{
	while (42)
	{
		init_select(serveur);
		if ((ft_select(serveur)) == FT_ERROR)
			return (ft_error("serveur", __FILE__, __LINE__));
		check_select(serveur);
	}
}
