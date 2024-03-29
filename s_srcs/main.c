/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 10:20:35 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 13:38:53 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

int						main(int ac, char **av)
{
	t_serveur			*serveur;

	ac--;
	av++;
	if (check_input(ac) == FT_ERROR)
		return (EXIT_FAILURE);
	if (!(serveur = init_serveur(ft_atoi(av[0]))))
	{
		ft_error("serveur", __FILE__, __LINE__);
		return (EXIT_FAILURE);
	}
	if ((loop(serveur)) == FT_ERROR)
		ft_error("serveur", __FILE__, __LINE__);
	if ((end_serveur(serveur)) == FT_ERROR)
	{
		ft_error("serveur", __FILE__, __LINE__);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
