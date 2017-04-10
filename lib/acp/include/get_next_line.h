/*
** get_next_line.h for matchstick in /home/arthur/delivery/CPE_2016_matchstick/include/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Mon Feb 13 21:11:00 2017 Arthur Philippe
** Last update Sun Feb 26 20:50:19 2017 Arthur Philippe
*/

#ifndef NEXT_LINE_H_
# define NEXT_LINE_H_

# include <unistd.h>
# include <stdlib.h>

# ifndef READ_SIZE
#  define READ_SIZE 100
# endif /* !READ_SIZE */

typedef struct	s_fd_track
{
  int		status;
  int		fd;
  int		idx;
  char		*buffer;
}		t_fd_track;

char	*get_next_line(const int fd);
int	gnl_fill_buffer(char **buffer_ptr, int fd);
char	*gnl_add_to_stack(char *stack, t_fd_track *file_ptr);
void	gnl_rebuff(t_fd_track *, int *);
int	my_strlen(char *);
void	*my_memset(void *str, int c, int size);

#endif /* !NEXT_LINE_H_ */
