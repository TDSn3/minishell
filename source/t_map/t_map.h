/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:11:42 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/21 12:16:09 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

void	map_add(t_map **lst, t_map *new);
t_map	*map_last(t_map *lst);
t_map	*map_new(char *content, t_type type);

#endif
