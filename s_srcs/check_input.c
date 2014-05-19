/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 10:12:38 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 10:24:54 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

int							check_input(int ac)
{
	if (ac != 1)
	{
		ft_putendl(S_USAGE);
		return (FT_ERROR);
	}
	return (0);
}
