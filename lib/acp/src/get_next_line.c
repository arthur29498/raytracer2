/*
** get_next_line.c for lacp in /home/arthur/Projects/new_gnl/lib/acp/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sun May  7 21:16:35 2017 Arthur Philippe
** Last update Mon May  8 11:12:45 2017 Arthur Philippe
*/

#include <stdio.h>
#include "str.h"
#include "get_next_line.h"

char	*my_strappend(char *s1, char *s2, int destroy_f)
{
  char	*outp;
  char	*old_s1;
  char	*old_s2;
  int	i;

  if (!(outp = malloc((my_strlen(s1) + my_strlen(s2) + 1))))
    return (NULL);
  i = 0;
  old_s1 = s1;
  old_s2 = s2;
  while (s1 && *s1)
    outp[i++] = *(s1++);
  while (s2 && *s2)
    outp[i++] = *(s2++);
  outp[i] = '\0';
  if (old_s1 && (destroy_f == 1 || destroy_f == 3))
    free(old_s1);
  if (old_s2 && (destroy_f == 2 || destroy_f == 3))
    free(old_s2);
  return (outp);
}

static char	*set_leftovers(char *stack, int *eof_f)
{
  char		*left_overs;
  int		idx;

  idx = 0;
  while (stack[idx] && stack[idx] != '\n' && stack[idx] != EOF)
    idx += 1;
  if (!stack[idx] || stack[idx] == EOF)
    {
      *eof_f = (stack[idx] == EOF && idx == 0) ? 1 : 0;
      return (NULL);
    }
  left_overs = my_strdup(&stack[idx + 1]);
  stack[idx] = '\0';
  return (left_overs);
}

static char	*reset_gnl(const int fd, int *old_fd, char *left_overs)
{
  *old_fd = fd;
  if (left_overs)
    free(left_overs);
  return (NULL);
}

char		*get_next_line(const int fd)
{
  char		*buffer;
  char		*stack;
  static char	*stack_leftover = NULL;
  int		eof_f;
  static int	old_fd = -2;

  if (fd != old_fd)
    stack_leftover = reset_gnl(fd, &old_fd, stack_leftover);
  if (!(buffer = ub_malloc(READ_SIZE + 1)))
    return (NULL);
  stack = (stack_leftover) ? my_strappend(NULL, stack_leftover, 2) : NULL;
  eof_f = 0;
  if (stack)
    stack_leftover = set_leftovers(stack, &eof_f);
  while (!eof_f && !stack_leftover && read(fd, buffer, READ_SIZE) > 0)
    {
      stack = my_strappend(stack, buffer, 1);
      stack_leftover = set_leftovers(stack, &eof_f);
    }
  free(buffer);
  if (!stack_leftover && stack)
    free(stack);
  return ((!stack_leftover) ? NULL : stack);
}
