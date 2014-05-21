/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 20:14:58 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/21 13:27:12 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int							main(int ac, char **av)
{
	t_client				*client;

	ac--;
	av++;
	if (check_input(ac, &av) == FT_ERROR)
		return (EXIT_FAILURE);
	if (!(client = init_client(av[0], ft_atoi(av[1]))))
	{
		ft_error("client", __FILE__, __LINE__);
		return (EXIT_FAILURE);
	}
	init_ncurse(client);
	loop_client(client);
	end_client(client);
	endwin();
	return (EXIT_SUCCESS);
}
