/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:44:40 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/16 13:44:44 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	if ((c == ' ') || (c == '\n') ||
		(c == '\t') || (c == '\v') ||
		(c == '\r') || (c == '\f'))
		return (1);
	else
		return (0);
}
