/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:49:02 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/08 17:00:25 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*str3;

	i = 0;
	j = 0;
	str3 = (char *)malloc((ft_strlen(str1) + ft_strlen(str2)) + 1);
	if (!str3)
		return (ft_free(&str1));
	while (str1[i])
	{
		str3[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		str3[i + j] = str2[j];
		j++;
	}
	str3[i + j] = '\0';
	ft_free(&str1);
	ft_free(&str2);
	return (str3);
}
