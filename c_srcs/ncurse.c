/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 15:46:33 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/21 18:02:53 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void						init_ncurse(t_client *client)
{
	int						maxx;

	client->win = initscr();
	noecho();
	keypad(client->win, 1);
	scrollok(client->win, 1);
	getmaxyx(client->win, client->maxy, maxx);
}
