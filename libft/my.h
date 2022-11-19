/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:19:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 11:03:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_H
# define MY_H

char			*my_strjoin_free(char **s1, char **s2);
long long int	my_atoi_hex(const char *nptr);
void			my_tab_reverse(int *tab, size_t size);

#endif