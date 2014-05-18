/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 10:53:24 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/13 13:46:46 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int						ft_error(char *bin, char *file, int line)
{
	ft_putstr(bin);
	ft_putstr(": Error detected in file: ");
	ft_putstr(file);
	ft_putstr(" at line ");
	ft_putnbrendl(line);
	return (FT_ERROR);
}
