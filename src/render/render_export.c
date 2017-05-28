/*
** render_export.c for raytracer in /home/arthur/Projects/raytracer2/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Wed Apr 19 16:02:34 2017 Arthur Philippe
** Last update Sun May 28 21:57:06 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "str.h"
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

char	*set_file_ext(char *origin)
{
  char	*out;
  int	idx;

  if (!origin)
    return (NULL);
  out = my_strdup(origin);
  idx = my_strlen(out) - 1;
  while (idx)
    {
      if (out[idx] == '.')
	{
	  out[idx] = '\0';
	  my_strcat(out, EXPORT_EXT);
	  return (out);
	}
      idx -= 1;
    }
  return (my_strdup(DEF_EXPRT));
}

int		export_render(char *file_name,
			      t_fbuffer *buffer)
{
  int		fd;
  sfUint8	*pixels;
  char		*new_f_name;

  if (!(new_f_name = set_file_ext(file_name)))
    return (-1);
  acp_print(HINT_EXPORT, new_f_name);
  if ((fd = open(new_f_name, O_CREAT | O_RDWR, S_IWUSR | S_IRUSR)) == -1)
    return (-1);
  free(new_f_name);
  pixels = buffer->pixels;
  buffer->pixels = NULL;
  if (write(fd, buffer, sizeof(t_fbuffer)) != sizeof(t_fbuffer))
    return (-1);
  if (write(fd, pixels, buffer->width * buffer->height * 4)
      != buffer->width * buffer->height * 4)
    return (-1);
  buffer->pixels = pixels;
  acp_print(MSG_SUCCES);
  return (0);
}
