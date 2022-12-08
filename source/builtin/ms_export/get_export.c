/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:42:02 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/08 09:07:55 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*																			  */
/*   Cherche strchr dans la struct "t_ls".									  */
/*																			  */
/* ************************************************************************** */
char	*get_export(char *strchr, t_input *input)
{
	t_ls	*copy;

	copy = input->export;
	while (copy)
	{
		if (str_chr_start_str(copy->content_one, strchr))
			return (copy->content_one);
		copy = copy->next;
	}
	return (NULL);
}
