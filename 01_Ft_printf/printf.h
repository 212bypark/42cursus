/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:47:06 by bypark            #+#    #+#             */
/*   Updated: 2021/06/23 18:07:17 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_data
{
	va_list ap;
	int		i;
	char	type;
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		num_base;
	int		num_sign;
}				t_data;

int				ft_printf(const char *format, ...);

int				ft_print_type(t_data *data);
int				ft_print_char(int c, t_data *data);
int				ft_print_str(char *str, t_data *data);
int				ft_print_nbr(unsigned long long num, t_data *data);

char			*ft_set_buffer(char *str, t_data *data);
int				ft_s_width(t_data *data, char **buff);

int				ft_nbr_len(unsigned long long num, t_data *data);
char			*ft_base(char type);

char			*ft_strchr(const char *s, int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *str);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
#endif
