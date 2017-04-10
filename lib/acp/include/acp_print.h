/*
** my.h for my_printf in /home/arthur/delivery/PSU_2016_my_printf
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Wed Nov  9 16:46:52 2016 Arthur Philippe
** Last update Wed Jan 25 17:48:20 2017 Arthur Philippe
*/

#ifndef ACP_PRINT_H_
# define ACP_PRINT_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	acp_print(char *, ...);
int	my_putchar(char);
int	my_putstr(char *);
int	my_putstr_and_nonascii(char *);
int	my_putchar_va(va_list);
int	my_putstr_va(va_list);
int	my_putstr_and_nonascii_va(va_list);
int	my_putnbr(int);
int	my_putnbr_va(va_list);
int	my_putlong(va_list);
int	my_putnbr_base(unsigned int, char *);
int	my_putlong_base(unsigned long, char *);
int	my_strlen(char *);
int	my_power_it(int, int);
long	my_power_long(long, int);
int	get_flag_rank(char **, va_list);
int	flag_x_hexa(va_list);
int	flag_X_hexa(va_list);
int	flag_o_octal(va_list);
int	flag_u_unsigned(va_list);
int	flag_p_pointer(va_list);
int	flag_b_binary(va_list);
int	long_flags(char **, va_list);
int	flag_x_hexa_long(va_list);
int	flag_X_hexa_long(va_list);
int	flag_o_octal_long(va_list);
int	flag_u_unsigned_long(va_list);
int	flag_b_binary_long(va_list);
int	flag_n_store(va_list, int);
int	min_char_count(int, int, char *);
int	nbr_prefix(int);
int	get_min_char_count(char **, va_list);
char	get_preformat(char **);
int	apply_preformat(int, int);
int	my_put_sign(long);
int	my_put_alt_prefix(char *, int);

#endif /* !ACP_PRINT_H_ */
