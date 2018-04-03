/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:17:08 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 17:28:15 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	if (s2[i] == '\0' && s1[i] == '\0')
		return (0);
	return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
}