#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

struct type
{
	long double i;
	char c;
	char *str;
};


void		ft_putchar(char c);
void		ft_putnbr(int i);
void		ft_putstr(char const *str);
int			ft_atoi(const char *str);
char		*ft_itoa(long n);
int			ft_strlen(const char *str);
void		ft_bzero(void *s, size_t n);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcat(char *s1, const char *s2);
int			ft_power(int i, int power);
char		*ft_utoa(unsigned int n);
char		*ft_convertbase(int i, int base);
int			ft_toupper(int c);
char		*ft_dtoa(long double i, int size);

char		*print_arg(int **tab, va_list *arg, char *str, const char *format);
int			**check_format(const char *format, int *i);

void		check_flags(int *tab, const char *format, int *i);
void		check_len(int *tab, const char *format, int *i);
void		check_accuracy(int *tab, const char *format, int *i);
int			check_modif(int *tab, char c);
int			check_type(int **tab, char c);

void		init_pt_tab(char *(**types)(va_list *arg, char *buffer, int *tab));

char		*get_int(va_list *arg, char *buffer, int *tab);
char		*get_octal(va_list *arg, char *buffer, int *tab);
char		*get_int_ns(va_list *arg, char *buffer, int *tab);
char		*get_hexa_low(va_list *arg, char *buffer, int *tab);
char		*get_hexa_up(va_list *arg, char *buffer, int *tab);
char		*get_double(va_list *arg, char *buffer, int *tab);
char		*get_char(va_list *arg, char *buffer, int *tab);
char		*get_str(va_list *arg, char *buffer, int *tab);

#endif
