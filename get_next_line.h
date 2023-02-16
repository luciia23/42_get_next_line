/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollado <lcollado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:13:20 by lcollado          #+#    #+#             */
/*   Updated: 2023/02/16 17:39:24 by lcollado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

//directivas de preprocesador
//evita la definición múltiple de una variable al utilizar la directiva "#ifndef"
# ifndef BUFFER_SIZE
# define  BUFFER_SIZE 4
#endif 


size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s);
char    *ft_strjoin(char *s1, char *s2);

#endif