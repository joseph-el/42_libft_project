/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:22:44 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/10/17 14:26:26 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *set, char c)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_is_size(char const *str, char const *set)
{
	int	url;
	int	i;
	int	len;

	url = 0;
	i = 0;
	len = ft_strlen(str) - 1;
	while (is_set(set, str[i++]))
	{
		url++;
		if (str[url] == '\0')
			return (0);
	}
	while (is_set(set, str[len]) && len >= 0)
	{
		url++;
		len--;
	}
	return ((ft_strlen(str)) - url);
}

static int	is_stop(char const *str, char const *set)
{
	int	stop;
	int	len;

	stop = 0;
	len = ft_strlen(str) - 1;
	while (len >= 0 && is_set(set, str[len]))
	{
		stop++;
		len--;
	}
	return (stop);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*p;
	char	*s;
	int		i;

	i = 0;
	if (!str || !set)
		return (NULL);
	p = malloc(sizeof(char) * (ft_is_size(str, set) + 1));
	if (!p)
		return (NULL);
	s = p;
	while (str[i] && is_set(set, str[i]))
		i++;
	while (str[i])
	{
		*p++ = str[i++];
		if (str[i + is_stop(str, set)] == '\0')
			break ;
	}
	*p = '\0';
	return (s);
}
