/*
** load_data.c for raytracer1 in /home/arthur/delivery/raytracer1/src/data_gathering/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Thu Feb 16 14:38:11 2017 Arthur Philippe
** Last update Tue Mar 14 14:13:45 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_data.h"

char	*file_to_buffer(char *file_name)
{
  int	file_descriptor;
  int	size;
  char	*buffer;

  buffer = malloc(sizeof(char) * BUFFER_SIZE);
  if (!buffer)
    return ((char *) 0);
  my_memset(buffer, '\0', BUFFER_SIZE);
  errno = 0;
  file_descriptor = open(file_name, O_RDONLY);
  if (file_descriptor == -1)
    return ((char *) fd_errors(errno, file_name));
  size = read(file_descriptor, buffer, BUFFER_SIZE - 1);
  if (size < 0)
    return ((char *) fd_errors(errno, file_name));
  buffer[BUFFER_SIZE - 1] = 0;
  close(file_descriptor);
  return (buffer);
}

int	detect_start_keyword(char *buffer, int *idx)
{
  while (buffer[*idx])
    {
      if (match(&buffer[*idx], OBJ_START))
	{
	  while (buffer[*idx] && buffer[*idx] != '\n')
	    *idx += 1;
	  return (1);
	}
      *idx += 1;
    }
  return (0);
}

void	set_objects_ids(t_object *list)
{
  int	id;

  id = 0;
  while (list)
    {
      list->id = id;
      id += 1;
      list = list->next;
    }
}

t_object	*get_objects_from_file(char *file_name)
{
  t_object	*objects;
  char		*buffer;
  int		i;

  acp_print("Loading objects from: \'%s\'...\n\n", file_name);
  buffer = file_to_buffer(file_name);
  if (!buffer)
    return (NULL);
  objects = NULL;
  i = 0;
  while (buffer[i])
    {
      if (detect_start_keyword(buffer, &i))
	objects = add_to_object_list(create_object(buffer, &i), objects);
    }
  check_list_content(objects, file_name);
  free(buffer);
  set_objects_ids(objects);
  return (objects);
}
