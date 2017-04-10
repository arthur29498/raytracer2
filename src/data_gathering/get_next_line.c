/*
** get_next_line.c for minishell1 in /home/arthur/delivery/PSU_2016_minishell1/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Jan 11 09:59:03 2017 Arthur Philippe
** Last update Sat Feb 18 11:03:44 2017 Arthur Philippe
*/

#include "get_next_line.h"
#include "acp.h"

char			*get_next_line(const int fd)
{
  static t_fd_track	f = (t_fd_track) {0, -1, 0, 0};
  int			size;
  char			*stack;

  size = 0;
  stack = (f.idx) ? gnl_add_to_stack(0, &f) : 0;
  if (f.status == 2)
    gnl_rebuff(&f, &size);
  if (fd != f.fd || ((f.status) == 1 && f.buffer[f.idx] == -1))
    {
      f = (t_fd_track) {0, fd, 0, f.buffer};
      gnl_rebuff(&f, &size);
    }
  while (size > 0 && !f.status)
    {
      stack = gnl_add_to_stack(stack, &f);
      if (f.status == 2)
	gnl_rebuff(&f, &size);
    }
  if (!stack || (!stack[0] && f.status == 0))
    return (0);
  return (stack);
}

char	*gnl_add_to_stack(char *stack, t_fd_track *f_pt)
{
  char	*new_stack;
  int	i1;
  int	i2;

  i1 = 0;
  i2 = f_pt->idx;
  new_stack = malloc(my_strlen(stack) + my_strlen(f_pt->buffer) + 1);
  if (my_strlen(stack))
    {
      while (stack[i1++])
	new_stack[i1 - 1] = stack[i1 - 1];
      i1 -= 1;
      free(stack);
    }
  while (f_pt->buffer[f_pt->idx] && f_pt->buffer[f_pt->idx] != '\n'
	 && f_pt->buffer[f_pt->idx] != -1)
    {
      new_stack[i1 + f_pt->idx - i2] = f_pt->buffer[f_pt->idx];
      f_pt->idx += 1;
    }
  f_pt->status = (f_pt->buffer[f_pt->idx] == '\n') ? 1 : 2;
  new_stack[i1 + f_pt->idx - i2] = 0;
  f_pt->idx += (f_pt->status == 1) ? 1 : 0;
  return (new_stack);
}

void	gnl_rebuff(t_fd_track *f_pt, int *size)
{
  free (f_pt->buffer);
  *size = gnl_fill_buffer(&(f_pt->buffer), f_pt->fd);
  f_pt->status = 0;
  f_pt->idx = 0;
}

int	gnl_fill_buffer(char **buffer_ptr, int fd)
{
  int	size;

  size = 0;
  *buffer_ptr = malloc(sizeof(char) * READ_SIZE + 1);
  if (*buffer_ptr)
    {
      size = read(fd, *buffer_ptr, READ_SIZE);
      if (buffer_ptr[0][0] == -1)
	return (-1);
      if (size > 0)
	{
	  buffer_ptr[0][size] = 0;
	  return (size);
	}
    }
  return (0);
}
