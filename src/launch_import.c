/*
** launch_import.c for raytracer in /home/arthur/Projects/raytracer2/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Apr 22 13:45:47 2017 Arthur Philippe
** Last update Sat Apr 22 15:44:11 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "raytracer.h"
#include "launch.h"
#include "acp.h"

int			framebuffer_from_file(char *file_name,
					      t_my_framebuffer *buffer)
{
  int			fd;
  t_my_framebuffer	ingest;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    return (-1);
  if (read(fd, &ingest, sizeof(t_my_framebuffer))
      != sizeof(t_my_framebuffer))
    return (-1);
  if (ingest.width != SC_W || ingest.height != SC_H)
    {
      acp_print("import error\n");
      return (-1);
    }
  if (read(fd, buffer->pixels, ingest.width * ingest.height * 4)
      != ingest.width * ingest.height * 4)
    return (-1);
  buffer->width = ingest.width;
  buffer->height = ingest.height;
  return (EXIT_SUCCESS);
}

int	import_launcher(char *file_name)
{
  t_my_window	w;

  if (!(w.buffer = my_framebuffer_create(SC_W, SC_H)))
    return (EXIT_FAIL);
  if ((framebuffer_from_file(file_name, w.buffer)) == -1)
    return (EXIT_FAIL);
  open_window(&w, file_name);
  while (window_loop(&w, NULL, file_name));
  return (EXIT_SUCCESS);
}
