/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 20:45:45 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/21 18:20:33 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void				loop_client(t_client *client)
{
	int				type;
	int				i;
	static int		type_enum[TYPE_SIZE] = TYPE_ENUM;
	static int		(*type_funct[TYPE_SIZE])(t_client *) = TYPE_FUNCT;

	while (42)
	{
		print_prompt(client);
		while ((type = ft_select(client)) == -1)
			;
		refresh();
		if (type == QUIT)
			break ;
		i = 0;
		while (i < TYPE_SIZE)
		{
			if (type == type_enum[i])
				type_funct[i](client);
			i++;
		}
	}
}

void				print_prompt(t_client *client)
{
	mvprintw(client->y, 0, "%s: ", client->nick);
	refresh();
}

int					wrong(t_client *client)
{
	client->y++;
	mvprintw(client->y, 0, "ERROR: wrong command");
	client->y = client->y + 2;
	wmove(client->win, client->y, 0);
	return (0);
}
