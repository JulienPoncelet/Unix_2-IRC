/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 10:53:24 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 10:42:56 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int						ft_error(char *bin, char *file, int line)
{
	ft_putstr(RED);
	ft_putstr(bin);
	ft_putstr(": Error detected in file: ");
	ft_putstr(WHITE);
	ft_putstr(file);
	ft_putstr(RED);
	ft_putstr(" at line ");
	ft_putstr(WHITE);
	ft_putnbrendl(line);
	return (FT_ERROR);
}
