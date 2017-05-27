/*
** objects_creation.c for raytracer1 in /home/arthur/delivery/raytracer1/src/data_gathering/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Feb 18 11:24:50 2017 Arthur Philippe
** Last update Sat May 27 12:33:53 2017 Arthur Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

static int	add_size(char *buffer, int *idx, t_object *new_object)
{
  if (buffer[*idx] == 'A')
    new_object->size_a = my_getnbr(&buffer[*idx + 2]);
  else if (buffer[*idx] == 'B')
    new_object->size_b = my_getnbr(&buffer[*idx + 2]);
  else
    return (0);
  return (1);
}

static int	add_rotation(char *buffer, int *idx, t_object *new_object)
{
  if (buffer[*idx] == 'r' && buffer[*idx + 1] == 'X')
    new_object->rot.x = my_getnbr(&buffer[*idx + 3]);
  else if (buffer[*idx] == 'r' && buffer[*idx + 1] == 'Y')
    new_object->rot.y = my_getnbr(&buffer[*idx + 3]);
  else if (buffer[*idx] == 'r' && buffer[*idx + 1] == 'Z')
    new_object->rot.z = my_getnbr(&buffer[*idx + 3]);
  else
    return (0);
  return (1);
}

static int	add_position(char *buffer, int *idx, t_object *new_object)
{
  if (buffer[*idx] == 'X')
    new_object->pos.x = my_getnbr(&buffer[*idx + 2]);
  else if (buffer[*idx] == 'Y')
    new_object->pos.y = my_getnbr(&buffer[*idx + 2]);
  else if (buffer[*idx] == 'Z')
    new_object->pos.z = my_getnbr(&buffer[*idx + 2]);
  else
    return (0);
  return (1);
}

static int	add_color(char *buffer, int *idx, t_object *new_object)
{
  if (buffer[*idx] == 'c' && buffer[*idx + 1] == 'R')
    new_object->col.r = my_getnbr(&buffer[*idx + 3]);
  else if (buffer[*idx] == 'c' && buffer[*idx + 1] == 'G')
    new_object->col.g = my_getnbr(&buffer[*idx + 3]);
  else if (buffer[*idx] == 'c' && buffer[*idx + 1] == 'B')
    new_object->col.b = my_getnbr(&buffer[*idx + 3]);
  else if (buffer[*idx] == 'c' && buffer[*idx + 1] == 'A')
    new_object->col.a = my_getnbr(&buffer[*idx + 3]);
  else
    return (0);
  return (1);
}

t_object	*create_object(char *buffer, int *idx)
{
  t_object	*new_object;

  if (!(new_object = create_list_node()))
    return (NULL);
  new_object->next = NULL;
  while (buffer[*idx])
    {
      if (buffer[*idx] != '#')
	{
	  add_size(buffer, idx, new_object);
	  add_rotation(buffer, idx, new_object);
	  add_position(buffer, idx, new_object);
	  add_color(buffer, idx, new_object);
	  add_limit(buffer, idx, new_object);
	  add_brightness_reflect(buffer, idx, new_object);
	  add_pr_texture(buffer, idx, new_object);
	  if (buffer[*idx] == 'T')
	    new_object->type = resolve_object_type(&buffer[*idx + 2]);
	}
      if (buffer[*idx] == 'E')
	break;
      while (buffer[*idx] && buffer[(*idx)++] != '\n');
    }
  return (new_object);
}
