/*
** str.h for lacp in /home/arthur/Projects/new_gnl/lib/acp/include/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sun May  7 19:54:42 2017 Arthur Philippe
** Last update Mon May  8 11:18:13 2017 Arthur Philippe
*/

#ifndef	STR_H_
# define STR_H_

# ifndef NULL
#  define NULL	0
# endif /* !NULL */

int	my_strlen(char *);
void	*ub_malloc(int);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *src);
char	*my_strcat(char *s1, char *s2);
int	match(char *s1, char *s2);
int	nmatch(char *s1, char *s2);

#endif /* !STR_H_ */
