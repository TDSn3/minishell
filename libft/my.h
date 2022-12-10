/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:19:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/10 21:57:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_H
# define MY_H

char			*my_strjoin_free(char **s1, char **s2);
long long int	my_atoi_hex(const char *nptr);
void			my_tab_reverse(int *tab, size_t size);
size_t			my_strdlen(char **strd);
char			**my_strdcpy(char **strd);
char			**my_strdjoin(char **strd, char *s);
int				my_strcmp(const char *s1, const char *s2);
char			*my_strdup_until(const char *s, char c);
int				my_strchr_pos(const char *s, char c);
int				my_strdfree(char ***strd);

#endif