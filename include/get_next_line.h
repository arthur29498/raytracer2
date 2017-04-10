/*
** get_next_line.h for getnextline in /home/arthur/delivery/CPE_2016_getnextline/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Mon Jan  2 13:06:36 2017 Arthur Philippe
** Last update Wed Jan 11 12:34:54 2017 Arthur Philippe
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

#endif /* !NEXT_LINE_H_ */
