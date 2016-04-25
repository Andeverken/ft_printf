/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:26:16 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/25 17:43:53 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memalloc(size_t size);
void		ft_putchar(char c);
void		ft_putnbr(int i);
void		ft_putstr(char const *str);
int			ft_atoi(const char *str);
char		*ft_itoa(long n);
int			ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
void		ft_bzero(void *s, size_t n);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcat(char *s1, const char *s2);
long long	ft_power(long long i, int power);
char		*ft_utoa(unsigned int n);
char		*ft_convertbase(unsigned long long i, int base);
int			ft_toupper(int c);
char		*ft_dtoa(long double i, int size);
char		*ft_round(char *str, int size);
int			size_forscient(double *i);
char		*arg_forscient(char *buffer, int n);
char		*arg_forscient_up(char *buffer, int n);
char		*fill_point(char *buffer, int **tab);
char		*ft_addzero(char *str, int size);
void		ft_delete_zero(char *str);

char		*print_arg(int **tab, va_list *arg, char *str, const char *format);
int			**check_format(va_list *arg, const char *format, int *i);

void		check_flags(int *tab, const char *format, int *i);
void		check_len(va_list *arg, int *tab, const char *format, int *i);
int			check_accuracy(va_list *arg, int *tab, const char *format, int *i);
void		check_modif(int *tab, const char *format, int *i);
int			check_type(int **tab, char c);

void		init_pt_tab(char *(**types)(va_list *arg, char *buffer, int **tab));
void		init_signed_tab(char *(**modif_signed)
			(va_list *arg, char *buffer, int **tab));
void		init_unsigned_tab(char *(**modif_unsigned)
			(va_list *arg, char *buffer, int **tab, int base));
void		init_diez_tab(char *(**diez)(char *tmp, char *buffer, int **tab));
int			ft_printf(const char *format, ...);

char		*get_nothing(va_list *arg, char *buffer, int **tab);
char		*get_int(va_list *arg, char *buffer, int **tab);
char		*get_octal(va_list *arg, char *buffer, int **tab);
char		*get_int_ns(va_list *arg, char *buffer, int **tab);
char		*get_hexa_low(va_list *arg, char *buffer, int **tab);
char		*get_hexa_up(va_list *arg, char *buffer, int **tab);
char		*get_double(va_list *arg, char *buffer, int **tab);
char		*get_char(va_list *arg, char *buffer, int **tab);
char		*get_str(va_list *arg, char *buffer, int **tab);
char		*get_scient(va_list *arg, char *buffer, int **tab);
char		*get_scient_up(va_list *arg, char *buffer, int **tab);
char		*get_point(va_list *arg, char *buffer, int **tab);
char		*get_shorter(va_list *arg, char *buffer, int **tab);
char		*get_shorter_up(va_list *arg, char *buffer, int **tab);
char		*get_binary(va_list *arg, char *buffer, int **tab);
char		*get_percent(va_list *arg, char *buffer, int **tab);
char		*get_long_str(va_list *arg, char *buffer, int **tab);

char		*get_short_short_int(va_list *arg, char *buffer, int **tab);
char		*get_short_int(va_list *arg, char *buffer, int **tab);
char		*get_normal_int(va_list *arg, char *buffer, int **tab);
char		*get_long_int(va_list *arg, char *buffer, int **tab);
char		*get_long_long_int(va_list *arg, char *buffer, int **tab);
char		*get_int_max(va_list *arg, char *buffer, int **tab);
char		*get_size_int(va_list *arg, char *buffer, int **tab);

char		*get_short_short_unsigned(va_list *arg, char *buffer, int **tab,
			int base);
char		*get_short_unsigned(va_list *arg, char *buffer, int **tab,
			int base);
char		*get_normal_unsigned(va_list *arg, char *buffer, int **tab,
			int base);
char		*get_long_unsigned(va_list *arg, char *buffer, int **tab, int base);
char		*get_long_long_unsigned(va_list *arg, char *buffer, int **tab,
			int base);
char		*get_unsigned_max(va_list *arg, char *buffer, int **tab, int base);
char		*get_size_unsigned(va_list *arg, char *buffer, int **tab, int base);

char		*ft_apply_flag(int **tab, char *buffer);
char		*apply_diez_octal(char *tmp, char *buffer, int **tab);
char		*apply_diez_hexa_low(char *tmp, char *buffer, int **tab);
char		*apply_diez_hexa_up(char *tmp, char *buffer, int **tab);
char		*apply_diez_double(char *tmp, char *buffer, int **tab);
char		*apply_diez_scient_low(char *tmp, char *buffer, int **tab);
char		*apply_diez_shorter_low(char *tmp, char *buffer, int **tab);
char		*apply_diez_binary(char *tmp, char *buffer, int **tab);

#endif
