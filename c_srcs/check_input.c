/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 20:05:42 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 14:06:21 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int							check_input(int ac, char ***av)
{
	if (ac == 2)
	{
		if (ft_strequ("localhost", *av[0]))
			*av[0] = "127.0.0.1";
		return (0);
	}
	ft_putendl(C_USAGE);
	return (FT_ERROR);
}
