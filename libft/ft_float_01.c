/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:40:13 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/17 12:44:34 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_float_01(float f)
{
	if (f < 0)
		return (0);
	if (f > 1)
		return (1);
	else
		return (f);
}