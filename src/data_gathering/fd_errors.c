/*
** wf_errors.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 13:48:42 2016 Arthur Philippe
** Last update Sat Mar 18 11:22:07 2017 Arthur Philippe
*/

#include <unistd.h>
#include "raytracer_messages.h"

void	*fd_errors(int e, char *f_name)
{
  acp_putstr(STDERR_FILENO, MSG_FD_ERROR);
  acp_putstr(STDERR_FILENO, f_name);
  acp_putstr(STDERR_FILENO, ": ");
  if (e == 2)
    acp_putstr(STDERR_FILENO, MSG_MISSING_FILE);
  else if (e == 13)
    acp_putstr(STDERR_FILENO, MSG_PERMISSION);
  else if (e == 21)
    acp_putstr(STDERR_FILENO, MSG_IS_DIR);
  else
    acp_putstr(STDERR_FILENO, MSG_UNKNOWN);
  return (0);
}
